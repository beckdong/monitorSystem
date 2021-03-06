/*************************************************************************
	> File Name: getNodeFreeMemory.c
	> Author:wuhonglei 
	> Mail:1017368065@qq.com 
	> Created Time: Sat 31 Oct 2015 10:43:25 AM CST
    > Description: virNodeGetFreeMemory 
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
int main(int argc, char *argv[])
{
    virConnectPtr conn;
    unsigned long long node_free_memory;
    conn = virConnectOpen("qemu:///system");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to qemu:///system\n");
        return 1;
    }
    node_free_memory = virNodeGetFreeMemory(conn);
    fprintf(stdout, "Node free memory: %llu bytes\n", node_free_memory);
    virConnectClose(conn);
    return 0;
}
