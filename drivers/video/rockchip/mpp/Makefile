# SPDX-License-Identifier: (GPL-2.0+ OR MIT)
#
# Rockchip MPP (Media Process Platform) driver Makefile
# Ported from the Rockchip BSP kernel (kernel-5.10) to mainline linux-6.12.y.

MPP_VERSION := mainline-6.12-port

rk_vcodec-objs := mpp_service.o mpp_common.o mpp_iommu.o

CFLAGS_mpp_service.o += -DMPP_VERSION="\"$(MPP_VERSION)\""

rk_vcodec-$(CONFIG_ROCKCHIP_MPP_RKVDEC)	+= mpp_rkvdec.o
rk_vcodec-$(CONFIG_ROCKCHIP_MPP_VDPU2)	+= mpp_vdpu2.o
rk_vcodec-$(CONFIG_ROCKCHIP_MPP_VEPU2)	+= mpp_vepu2.o
rk_vcodec-$(CONFIG_CPU_PX30)		+= hack/mpp_hack_px30.o

obj-$(CONFIG_ROCKCHIP_MPP_SERVICE) += rk_vcodec.o
