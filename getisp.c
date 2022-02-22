#include <stdio.h>

#include <mpi_ae.h>
#include <mpi_awb.h>
#include <mpi_isp.h>
#include <mpi_vpss.h>

#define GETTER(x, y) HI_MPI_##x##_Get##y
#define SETTER(x, y) HI_MPI_##x##_Set##y

#define DUMP(sys, name, st)                                                    \
  {                                                                            \
    st attr;                                                                   \
    if (GETTER(sys, name)(0, &attr) != HI_SUCCESS) {                           \
      fprintf(stderr, "Cannot do HI_MPI_" #sys "_Get" #name "\n");             \
      exit(1);                                                                 \
    }                                                                          \
    FILE *f = fopen(#name, "wb");                                              \
    fwrite(&attr, 1, sizeof(attr), f);                                         \
    fclose(f);                                                                 \
  }

#define LOAD(sys, name, st)                                                    \
  {                                                                            \
    st old;                                                                    \
    if (GETTER(sys, name)(0, &old) != HI_SUCCESS) {                            \
      fprintf(stderr, "Cannot do HI_MPI_" #sys "_Get" #name "\n");             \
      exit(1);                                                                 \
    }                                                                          \
    st attr = {0};                                                             \
    FILE *f = fopen(#name, "rb");                                              \
    fread(&attr, 1, sizeof(attr), f);                                          \
    fclose(f);                                                                 \
    if (memcmp(&old, &attr, sizeof(attr)))                                     \
      printf(#name " differ\n");                                               \
    if (SETTER(sys, name)(0, &attr) != HI_SUCCESS) {                           \
      fprintf(stderr, "Cannot do HI_MPI_" #sys "_Set" #name "\n");             \
      exit(1);                                                                 \
    }                                                                          \
  }

#ifdef LOADER
#define OP DUMP
#else
#define OP LOAD
#endif

int main() {
  OP(ISP, AWBAttrEx, ISP_AWB_ATTR_EX_S);
  OP(ISP, BlackLevelAttr, ISP_BLACK_LEVEL_S);
  OP(ISP, CAAttr, ISP_CA_ATTR_S);
  OP(ISP, CCMAttr, ISP_COLORMATRIX_ATTR_S);
  OP(ISP, CSCAttr, ISP_CSC_ATTR_S);
  OP(ISP, ColorToneAttr, ISP_COLOR_TONE_ATTR_S);
  OP(ISP, CtrlParam, ISP_CTRL_PARAM_S);
  OP(ISP, DPDynamicAttr, ISP_DP_DYNAMIC_ATTR_S);
  OP(ISP, DRCAttr, ISP_DRC_ATTR_S);
  OP(ISP, DehazeAttr, ISP_DEHAZE_ATTR_S);
  OP(ISP, ExposureAttr, ISP_EXPOSURE_ATTR_S);
  OP(ISP, FSWDRAttr, ISP_WDR_FS_ATTR_S);
  OP(ISP, GammaAttr, ISP_GAMMA_ATTR_S);
  OP(ISP, IspSharpenAttr, ISP_SHARPEN_ATTR_S);
  OP(ISP, LDCIAttr, ISP_LDCI_ATTR_S);
  OP(ISP, LocalCacAttr, ISP_LOCAL_CAC_ATTR_S);
  OP(ISP, MeshShadingAttr, ISP_SHADING_ATTR_S);
  OP(ISP, NRAttr, ISP_NR_ATTR_S);
  OP(ISP, PubAttr, ISP_PUB_ATTR_S);
  OP(ISP, SaturationAttr, ISP_SATURATION_ATTR_S);
  OP(ISP, SmartExposureAttr, ISP_SMART_EXPOSURE_ATTR_S);
  OP(ISP, StatisticsConfig, ISP_STATISTICS_CFG_S);
  OP(ISP, WBAttr, ISP_WB_ATTR_S);
  OP(ISP, WDRExposureAttr, ISP_WDR_EXPOSURE_ATTR_S);
  OP(VPSS, GrpNRXParam, VPSS_GRP_NRX_PARAM_S);
}

#ifndef LOADER
__attribute__((visibility("default"))) const unsigned short int *__ctype_b;

__attribute__((visibility("default"))) int __fgetc_unlocked(FILE *stream) {
  return fgetc(stream);
}

__attribute__((visibility("default"))) size_t _stdlib_mb_cur_max(void) {
  return 0;
}

void *mmap64(void *start, size_t len, int prot, int flags, int fd, off_t off);
__attribute__((visibility("default"))) void *mmap(void *start, size_t len,
                                                  int prot, int flags, int fd,
                                                  uint32_t off, uint32_t off2) {

  return mmap64(start, len, prot, flags, fd, off);
}
#endif
