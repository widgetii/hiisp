#include <stdio.h>

#include <mpi_ae.h>
#include <mpi_awb.h>
#include <mpi_isp.h>

#define DUMP(name, st)                                                         \
  {                                                                            \
    st attr;                                                                   \
    if (HI_MPI_ISP_Get##name(0, &attr) != HI_SUCCESS) {                        \
      fprintf(stderr, "Cannot do HI_MPI_ISP_Get" #name "\n");                  \
      exit(1);                                                                 \
    }                                                                          \
    FILE *f = fopen(#name, "wb");                                              \
    fwrite(&attr, 1, sizeof(attr), f);                                         \
    fclose(f);                                                                 \
  }

#define LOAD(name, st)                                                         \
  {                                                                            \
    st old;                                                                    \
    if (HI_MPI_ISP_Get##name(0, &old) != HI_SUCCESS) {                         \
      fprintf(stderr, "Cannot do HI_MPI_ISP_Get" #name "\n");                  \
      exit(1);                                                                 \
    }                                                                          \
    st attr = {0};                                                             \
    FILE *f = fopen(#name, "rb");                                              \
    fread(&attr, 1, sizeof(attr), f);                                          \
    fclose(f);                                                                 \
    if (memcmp(&old, &attr, sizeof(attr)))                                     \
      printf(#name " differ\n");                                               \
    if (HI_MPI_ISP_Set##name(0, &attr) != HI_SUCCESS) {                        \
      fprintf(stderr, "Cannot do HI_MPI_ISP_Set" #name "\n");                  \
      exit(1);                                                                 \
    }                                                                          \
  }

#ifdef LOADER
#define OP DUMP
#else
#define OP LOAD
#endif

int main() {
  OP(AWBAttrEx, ISP_AWB_ATTR_EX_S);
  OP(BlackLevelAttr, ISP_BLACK_LEVEL_S);
  OP(CAAttr, ISP_CA_ATTR_S);
  OP(CCMAttr, ISP_COLORMATRIX_ATTR_S);
  OP(CSCAttr, ISP_CSC_ATTR_S);
  OP(ColorToneAttr, ISP_COLOR_TONE_ATTR_S);
  OP(CtrlParam, ISP_CTRL_PARAM_S);
  OP(DPDynamicAttr, ISP_DP_DYNAMIC_ATTR_S);
  OP(DRCAttr, ISP_DRC_ATTR_S);
  OP(DehazeAttr, ISP_DEHAZE_ATTR_S);
  OP(ExposureAttr, ISP_EXPOSURE_ATTR_S);
  OP(FSWDRAttr, ISP_WDR_FS_ATTR_S);
  OP(GammaAttr, ISP_GAMMA_ATTR_S);
  OP(IspSharpenAttr, ISP_SHARPEN_ATTR_S);
  OP(LDCIAttr, ISP_LDCI_ATTR_S);
  OP(LocalCacAttr, ISP_LOCAL_CAC_ATTR_S);
  OP(MeshShadingAttr, ISP_SHADING_ATTR_S);
  OP(NRAttr, ISP_NR_ATTR_S);
  OP(PubAttr, ISP_PUB_ATTR_S);
  OP(SaturationAttr, ISP_SATURATION_ATTR_S);
  OP(SmartExposureAttr, ISP_SMART_EXPOSURE_ATTR_S);
  OP(StatisticsConfig, ISP_STATISTICS_CFG_S);
  OP(WBAttr, ISP_WB_ATTR_S);
  OP(WDRExposureAttr, ISP_WDR_EXPOSURE_ATTR_S);
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
