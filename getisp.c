#include <stdio.h>

#include <mpi_ae.h>
#include <mpi_awb.h>
#include <mpi_isp.h>

#define DUMP(name, st) \
{ \
	st attr; \
	int ret = HI_MPI_ISP_Get##name(0, &attr); \
	if (ret != HI_SUCCESS) { \
		fprintf(stderr, "Cannot do HI_MPI_ISP_Get" #name "\n"); \
		exit(1); \
	} \
	FILE* f = fopen(#name, "wb"); \
	fwrite(&attr, 1, sizeof(attr), f); \
	fclose(f); \
}

int main() {
	DUMP(AWBAttrEx, ISP_AWB_ATTR_EX_S);
}

__attribute__((visibility("default"))) const unsigned short int *__ctype_b;

__attribute__((visibility("default"))) int __fgetc_unlocked(FILE *stream) {
    return fgetc(stream);
}

__attribute__((visibility("default"))) size_t _stdlib_mb_cur_max(void) {
    return 0;
}
