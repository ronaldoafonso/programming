
#ifndef __ACD__
#define __ACD__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <libiptc/libiptc.h>


typedef struct _Entry {
    struct ipt_entry entry;
    struct xt_standard_target target;
} Entry;


static int add_ipt_entry(const char *, const char *,
                         const char *, const char *);
static int del_ipt_entry(const char *, const char *,
                         const char *, const char *);

#endif
