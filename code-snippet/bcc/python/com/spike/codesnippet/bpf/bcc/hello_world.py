# -*- coding: utf-8 -*-

"""

@author: zhoujiagen
Created on 01/08/2020 4:17 PM
"""

from bcc import BPF

BPF(text='int kprobe__sys_clone(void *ctx) { bpf_trace_printk("Hello, World!\\n"); return 0; }').trace_print()
