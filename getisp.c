#include <stdio.h>

#include <mpi_ae.h>
#include <mpi_awb.h>
#include <mpi_isp.h>

#define DUMP(name, st)                                                         \
  {                                                                            \
    st attr;                                                                   \
    int ret = HI_MPI_ISP_Get##name(0, &attr);                                  \
    if (ret != HI_SUCCESS) {                                                   \
      fprintf(stderr, "Cannot do HI_MPI_ISP_Get" #name "\n");                  \
      exit(1);                                                                 \
    }                                                                          \
    FILE *f = fopen(#name, "wb");                                              \
    fwrite(&attr, 1, sizeof(attr), f);                                         \
    fclose(f);                                                                 \
  }

int main() {
  DUMP(AWBAttrEx, ISP_AWB_ATTR_EX_S);
  DUMP(BlackLevelAttr, ISP_BLACK_LEVEL_S);
  DUMP(CAAttr, ISP_CA_ATTR_S);
  DUMP(CCMAttr, ISP_COLORMATRIX_ATTR_S);
  DUMP(CSCAttr, ISP_CSC_ATTR_S);
  DUMP(ColorToneAttr, ISP_COLOR_TONE_ATTR_S);
  DUMP(CtrlParam, ISP_CTRL_PARAM_S);
  DUMP(DPDynamicAttr, ISP_DP_DYNAMIC_ATTR_S);
  DUMP(DRCAttr, ISP_DRC_ATTR_S);
  DUMP(DehazeAttr, ISP_DEHAZE_ATTR_S);
  DUMP(ExposureAttr, ISP_EXPOSURE_ATTR_S);
  DUMP(FSWDRAttr, ISP_WDR_FS_ATTR_S);
  DUMP(GammaAttr, ISP_GAMMA_ATTR_S);
  DUMP(IspSharpenAttr, ISP_SHARPEN_ATTR_S);
  DUMP(LDCIAttr, ISP_LDCI_ATTR_S);
  DUMP(LocalCacAttr, ISP_LOCAL_CAC_ATTR_S);
  DUMP(MeshShadingAttr, ISP_SHADING_ATTR_S);
  DUMP(NRAttr, ISP_NR_ATTR_S);
  DUMP(PubAttr, ISP_PUB_ATTR_S);
  DUMP(SaturationAttr, ISP_SATURATION_ATTR_S);
  DUMP(SmartExposureAttr, ISP_SMART_EXPOSURE_ATTR_S);
  DUMP(StatisticsConfig, ISP_STATISTICS_CFG_S);
  DUMP(WBAttr, ISP_WB_ATTR_S);
  DUMP(WDRExposureAttr, ISP_WDR_EXPOSURE_ATTR_S);
}

__attribute__((visibility("default"))) const unsigned short int *__ctype_b;

__attribute__((visibility("default"))) int __fgetc_unlocked(FILE *stream) {
  return fgetc(stream);
}

__attribute__((visibility("default"))) size_t _stdlib_mb_cur_max(void) {
  return 0;
}
