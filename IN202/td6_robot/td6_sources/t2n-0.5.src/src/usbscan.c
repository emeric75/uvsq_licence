
/*
test de scan sur un port usb ...
*/
#include "usb.h"
#include <string.h>
#include <stdio.h>

// USB Générique : recherche d'un device particulier
struct usb_device* find_usb_dev(
	u_int16_t vendor,
	u_int16_t product
){
	struct usb_bus *busses, *bus;
	struct usb_device *devs, *d;
	u_int16_t v, p;

	usb_init();
	usb_find_busses();
	usb_find_devices();
	busses = usb_get_busses();
	for(bus = busses; bus;  bus = bus->next){
		printf("bus dirname=%s\n", bus->dirname);
		devs = bus->devices;
		for(d=devs; d; d=d->next){
			v = d->descriptor.idVendor;
			p = d->descriptor.idProduct;
			printf("  dev filename=%s, vendor=0x%04x, product=0x%04x\n",
				d->filename, v, p
			);
			if((v == vendor) && (p==product)) return d;
		}
	}
	return NULL;
}

int main(){
	struct usb_device *d;
	d = find_usb_dev(-1,-1);
	return 0;
}
