// Cyanide.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <pcap.h>
#include <stdio.h>


void getdevices()
{
	pcap_if_t *devices;
    pcap_if_t *counter;
    int i=0;
    char errbuf[PCAP_ERRBUF_SIZE];
	pcap_addr* address;
	sockaddr* IP;
    
	//Introduce the programme
	printf("				Cyanide!\n");
	printf("				========");

    /* Retrieve the device list from the local machine */
    if (pcap_findalldevs(&devices, errbuf) == -1)
    {
        fprintf(stderr,"Error in pcap_findalldevs_ex: %s\n", errbuf);
        exit(1);
    }
    
    /* Print the list */
    for(counter= devices; counter != NULL; counter= counter->next)
    {
        if (counter->description)
            printf("\n \n  %d. %s", ++i, counter->description);
        else
            printf(" (No description available) \n \n");

		if(counter->addresses)
		{
			address = counter->addresses;
			IP = address->addr;
			printf(" (%d)", IP);
		}
		else
			{
				printf(" (No IP address available)");
		}

    }
    
    if (i == 0)
    {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
    }

    /* We don't need any more the device list. Free it */
    pcap_freealldevs(devices);
}

char* getIP(sockaddr conversionAddress)
{
	return "a";
}

int main()
{
	char input;
	getdevices();

	scanf_s(&input);
	return 0;
}

