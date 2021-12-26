#ifndef __XBOOT_H__
#define __XBOOT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <xconfigs.h>
#include <endian.h>
#include <sizes.h>
#include <barrier.h>
#include <atomic.h>
#include <irqflags.h>
#include <spinlock.h>
#include <smp.h>
#include <types.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <ctype.h>
#include <errno.h>
#include <environ.h>
#include <byteorder.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <locale.h>
#include <shash.h>
#include <log2.h>
#include <path.h>
#include <time.h>
#include <math.h>
#include <exit.h>
#include <io.h>
#include <bcd.h>
#include <div.h>
#include <list.h>
#include <lsort.h>
#include <slist.h>
#include <hmap.h>
#include <fifo.h>
#include <queue.h>
#include <ssize.h>
#include <spring.h>
#include <malloc.h>
#include <charset.h>
#include <version.h>
#include <xboot/kobj.h>
#include <xboot/ktime.h>
#include <xboot/seqlock.h>
#include <xboot/event.h>
#include <xboot/profiler.h>
#include <xboot/notifier.h>
#include <xboot/initcall.h>
#include <xboot/machine.h>
#include <xboot/dtree.h>
#include <xboot/device.h>
#include <xboot/driver.h>
#include <xboot/task.h>
#include <xboot/mutex.h>
#include <xboot/waiter.h>
#include <xboot/channel.h>
#include <xboot/window.h>
#include <xboot/module.h>
#include <xboot/setting.h>
#include <xboot/sync.h>
#include <time/delay.h>
#include <time/timer.h>
#include <vfs/vfs.h>
#include <xfs/xfs.h>
#include <shell/shell.h>
#include <clockevent/clockevent.h>
#include <clocksource/clocksource.h>
#include <framebuffer/framebuffer.h>
#include <sound/sound.h>
#include <audio/audio.h>
#include <block/block.h>
#include <camera/camera.h>
#include <vision/vision.h>
#include <vision/colormap.h>
#include <vision/dilate.h>
#include <vision/dither.h>
#include <vision/erode.h>
#include <vision/gray.h>
#include <vision/inrange.h>
#include <vision/invert.h>
#include <vision/sepia.h>
#include <vision/threshold.h>
#include <xui/xui.h>
#include <xui/window.h>
#include <xui/popup.h>
#include <xui/panel.h>
#include <xui/collapse.h>
#include <xui/tree.h>
#include <xui/button.h>
#include <xui/checkbox.h>
#include <xui/radio.h>
#include <xui/toggle.h>
#include <xui/tabbar.h>
#include <xui/slider.h>
#include <xui/number.h>
#include <xui/textedit.h>
#include <xui/colorpicker.h>
#include <xui/glass.h>
#include <xui/image.h>
#include <xui/icon.h>
#include <xui/badge.h>
#include <xui/progress.h>
#include <xui/radialbar.h>
#include <xui/spinner.h>
#include <xui/split.h>
#include <xui/label.h>
#include <xui/text.h>

#ifdef __cplusplus
}
#endif

#endif /* __XBOOT_H__ */
