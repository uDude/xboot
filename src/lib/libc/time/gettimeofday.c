/*
 * libc/time/gettimeofday.c
 */

#include <time.h>
#include <rtc/rtc.h>
#include <clocksource/clocksource.h>
#include <xboot/module.h>

int64_t time_of_day_adjust = 0;

static uint32_t rtc_time_to_secs(struct rtc_time_t * rt)
{
	int month = rt->month, year = rt->year;

	if(0 >= (int)(month -= 2))
	{
		month += 12;
		year -= 1;
	}
	return ((((uint32_t)(year / 4 - year / 100 + year / 400 + 367 * month / 12 + rt->day) + year * 365 - 719499) * 24 + rt->hour) * 60 + rt->minute) * 60 + rt->second;
}

int gettimeofday(struct timeval * tv, void * tz)
{
	static ktime_t old = { -30000000000LL };

	if(!tv)
		return -1;
	ktime_t now = ktime_get();
	if(ktime_after(now, ktime_add_ms(old, 30000)))
	{
		struct rtc_t * rtc = search_first_rtc();
		struct rtc_time_t t;
		if(rtc && rtc_gettime(rtc, &t))
			time_of_day_adjust = (int64_t)rtc_time_to_secs(&t) * 1000000000ULL - ktime_to_ns(now);
		old = now;
	}
	int64_t ns = ktime_to_ns(now) + time_of_day_adjust;
	tv->tv_sec = ns / 1000000000ULL;
	tv->tv_usec = (ns % 1000000000ULL) / 1000;
	return 0;
}
EXPORT_SYMBOL(gettimeofday);
