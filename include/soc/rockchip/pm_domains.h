/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright 2022, The Chromium OS Authors. All rights reserved.
 */

#ifndef __SOC_ROCKCHIP_PM_DOMAINS_H__
#define __SOC_ROCKCHIP_PM_DOMAINS_H__

struct device;

#ifdef CONFIG_ROCKCHIP_PM_DOMAINS

int rockchip_pmu_block(void);
void rockchip_pmu_unblock(void);

#else /* CONFIG_ROCKCHIP_PM_DOMAINS */

static inline int rockchip_pmu_block(void)
{
	return 0;
}

static inline void rockchip_pmu_unblock(void) { }

#endif /* CONFIG_ROCKCHIP_PM_DOMAINS */

/*
 * Compatibility helpers used by the Rockchip MPP (media process platform)
 * drivers ported from the Rockchip BSP kernel.
 *
 * The upstream rockchip power domain driver does not export the BSP
 * power-domain/idle-request helpers. The MPP drivers use them to keep the
 * bus quiet around hardware resets, which is not required on the SoCs
 * supported here (mainline resets the VPU blocks with the CRU reset
 * controls only), so provide safe no-op implementations.
 */
#if defined(CONFIG_ROCKCHIP_MPP_SERVICE) || defined(CONFIG_ROCKCHIP_MPP_SERVICE_MODULE)

static inline int rockchip_pmu_idle_request(struct device *dev, bool idle)
{
	return 0;
}

static inline int rockchip_pmu_pd_is_on(struct device *dev)
{
	/* The power domain is managed through runtime PM, report "on" so
	 * callers do not try to power-cycle it behind genpd's back.
	 */
	return true;
}

static inline int rockchip_pmu_pd_on(struct device *dev)
{
	return 0;
}

static inline int rockchip_pmu_pd_off(struct device *dev)
{
	return 0;
}

#endif /* CONFIG_ROCKCHIP_MPP_SERVICE */

#endif /* __SOC_ROCKCHIP_PM_DOMAINS_H__ */
