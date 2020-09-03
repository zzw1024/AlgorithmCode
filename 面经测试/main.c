//#include <stdio.h>
//
//typedef long Align;
//
//union  header
//{
//	struct 
//	{
//		union header *ptr;
//		unsigned size;
//	}s;
//	Align x;
//};
//
//typedef union header Header;
//
//static Header base;
//static Header *freep = NULL;
//
//void *malloc(unsigned nbytes)
//{
//	Header *p, *prevp;
//	Header *moreroce(unsigned);
//	unsigned nunits;
//
//	nunits = (nbytes + sizeof(Header) - 1 / sizeof(union header) + 1);
//	if ((prevp = freep) == NULL)
//	{
//		base.s.ptr = freeptr = prevptr;
//	}
//}