#ifndef __NET_H__
#define __NET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <xboot.h>

enum socket_type_t {
	SOCKET_TYPE_TCP		= 0,
	SOCKET_TYPE_UDP		= 1,
};

struct socket_t {
	struct net_t * net;
	void * priv;
};

struct net_t
{
	char * name;

	struct socket_t * (*connect)(struct net_t * net, enum socket_type_t type, const char * ip, int port);
	struct socket_t * (*listen)(struct net_t * net, enum socket_type_t type, const char * ip, int port);
	int (*accept)(struct net_t * net, struct socket_t * s);
	int (*close)(struct net_t * net, struct socket_t * s);
	int (*read)(struct net_t * net, struct socket_t * s, void * buf, int count);
	int (*write)(struct net_t * net, struct socket_t * s, void * buf, int count);
	int (*ioctl)(struct net_t * net, const char * cmd, void * arg);

	void * priv;
};

struct net_t * search_net(const char * name);
struct net_t * search_first_net(void);
struct device_t * register_net(struct net_t * net, struct driver_t * drv);
void unregister_net(struct net_t * net);

#ifdef __cplusplus
}
#endif

#endif /* __NET_H__ */
