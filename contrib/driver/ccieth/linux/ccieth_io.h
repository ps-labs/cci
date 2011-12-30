/*
 * CCI over Ethernet
 * Copyright © INRIA 2011
 */

#ifndef CCIETH_IO_H
#define CCIETH_IO_H 1

#include <linux/types.h>
#include <linux/ioctl.h>

#define CCIETH_IOCTL_MAGIC 'C'

struct ccieth_ioctl_get_info {
	__u8 addr[6];
	__u8 pad1[2];
	/* 8 */
	__u16 max_send_size;
	__u16 pci_domain;
	__u8 pci_bus;
	__u8 pci_dev;
	__u8 pci_func;
	__u8 pad2;
	/* 16 */
	__u64 rate;
	/* 24 */
};
#define CCIETH_IOCTL_GET_INFO _IOW(CCIETH_IOCTL_MAGIC, 0x1, struct ccieth_ioctl_get_info)

struct ccieth_ioctl_create_endpoint {
	__u8 addr[6];
	__u8 pad1[2];
	/* 8 */
	__u32 id;
	__u32 pad2;
	/* 16 */
};
#define CCIETH_IOCTL_CREATE_ENDPOINT _IOWR(CCIETH_IOCTL_MAGIC, 0x2, struct ccieth_ioctl_create_endpoint)

struct ccieth_ioctl_get_event {
	__u8 type;
	__u8 pad1;
	__u16 data_length;
	__u32 data_offset;
	/* 8 */
	__u32 event_offset;	/* FIXME: not needed when passing events through the mmap'ed recvq */
	__u32 pad2;
	/* 16 */
};
#define CCIETH_IOCTL_GET_EVENT _IOW(CCIETH_IOCTL_MAGIC, 0x3, struct ccieth_ioctl_get_event)

struct ccieth_ioctl_return_event {
	__u32 event_offset;
};
#define CCIETH_IOCTL_RETURN_EVENT _IOR(CCIETH_IOCTL_MAGIC, 0x4, struct ccieth_ioctl_return_event)

struct ccieth_ioctl_send_connect {
	__u8 dest_addr[6];
	__u8 pad1[2];
	/* 8 */
	__u32 dest_eid;
	__u32 conn_id;
	/* 16 */
};
#define CCIETH_IOCTL_SEND_CONNECT _IOWR(CCIETH_IOCTL_MAGIC, 0x5, struct ccieth_ioctl_send_connect)

/* FIXME: enforce matching with enum cci_event_type */
#define CCIETH_IOCTL_EVENT_CONNECT_REQUEST 6

#endif /* CCIETH_IO_H */
