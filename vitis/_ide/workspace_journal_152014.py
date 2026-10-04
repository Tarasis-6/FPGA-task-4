# 2026-09-29T19:21:33.971035
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis")

platform = client.get_component(name="platform")
status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_1_wrapper.xsa")

status = platform.build()

status = platform.build()

domain = platform.get_domain(name="zynq_fsbl")

status = domain.set_config(option = "lib", param = "XILTIMER_tick_timer", value = "axi_timer_0", lib_name="xiltimer")

status = platform.build()

status = domain.set_config(option = "lib", param = "XILTIMER_sleep_timer", value = "axi_timer_0", lib_name="xiltimer")

status = domain.set_config(option = "lib", param = "XILTIMER_sleep_timer", value = "ps7_scutimer_0", lib_name="xiltimer")

status = platform.build()

status = platform.build()

comp = client.get_component(name="app_component")
comp.build()

status = platform.build()

comp.build()

status = domain.set_config(option = "lib", param = "XILTIMER_sleep_timer", value = "axi_timer_0", lib_name="xiltimer")

status = platform.build()

status = platform.build()

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

status = domain.set_config(option = "lib", param = "XILTIMER_sleep_timer", value = "Default", lib_name="xiltimer")

status = platform.build()

status = platform.build()

comp.build()

status = comp.clean()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.update_desc(desc="")

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_1_wrapper.xsa")

status = platform.build()

status = platform.build()

comp.build()

status = comp.clean()

vitis.dispose()

