/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) VeriSilicon Holdings Co., Ltd.
 */

#ifndef __VS_DRV_H__
#define __VS_DRV_H__

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/reset.h>

#include <drm/drm_fourcc.h>

#include "vs_dc_hw.h"

/*@pitch_alignment: buffer pitch alignment required by sub-devices.*/
struct vs_drm_device {
	struct drm_device base;
	unsigned int pitch_alignment;
	/* clocks */
	unsigned int clk_count;
	struct clk_bulk_data	*clks;
	struct reset_control	*rsts;
	struct vs_dc dc;
	int irq;
	struct regmap *dc_syscon_regmap;
};

static inline struct vs_drm_device *
to_vs_drm_private(const struct drm_device *dev)
{
	return container_of(dev, struct vs_drm_device, base);
}

#ifdef CONFIG_DRM_INNO_STARFIVE_HDMI
extern struct platform_driver starfive_hdmi_driver;
#endif

#endif /* __VS_DRV_H__ */
