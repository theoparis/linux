/* SPDX-License-Identifier: GPL-2.0-only */
/*
 *  Functions private to power supply class
 *
 *  Copyright © 2007  Anton Vorontsov <cbou@mail.ru>
 *  Copyright © 2004  Szabolcs Gyurko
 *  Copyright © 2003  Ian Molton <spyro@f2s.com>
 *
 *  Modified: 2004, Oct     Szabolcs Gyurko
 */

struct device;
struct device_type;
struct power_supply;

extern int power_supply_property_is_writeable(struct power_supply *psy,
					      enum power_supply_property psp);

#ifdef CONFIG_SYSFS

extern void __init power_supply_init_attrs(void);
extern int power_supply_uevent(const struct device *dev, struct kobj_uevent_env *env);
extern const struct attribute_group *power_supply_attr_groups[];

#else

static inline void power_supply_init_attrs(void) {}
#define power_supply_attr_groups NULL
#define power_supply_uevent NULL

#endif /* CONFIG_SYSFS */

#ifdef CONFIG_LEDS_TRIGGERS

extern void power_supply_update_leds(struct power_supply *psy);
extern int power_supply_create_triggers(struct power_supply *psy);
extern void power_supply_remove_triggers(struct power_supply *psy);

#else

static inline void power_supply_update_leds(struct power_supply *psy) {}
static inline int power_supply_create_triggers(struct power_supply *psy)
{ return 0; }
static inline void power_supply_remove_triggers(struct power_supply *psy) {}

#endif /* CONFIG_LEDS_TRIGGERS */

#ifdef CONFIG_POWER_SUPPLY_HWMON

int power_supply_add_hwmon_sysfs(struct power_supply *psy);
void power_supply_remove_hwmon_sysfs(struct power_supply *psy);

#else

static inline int power_supply_add_hwmon_sysfs(struct power_supply *psy)
{
	return 0;
}

static inline
void power_supply_remove_hwmon_sysfs(struct power_supply *psy) {}

#endif /* CONFIG_POWER_SUPPLY_HWMON */
