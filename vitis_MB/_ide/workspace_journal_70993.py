# 2026-10-04T15:51:22.495510
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis_MB")

platform = client.create_platform_component(name = "platform_MB",hw_design = "$COMPONENT_LOCATION/../../design_2_wrapper.xsa",os = "standalone",cpu = "microblaze_0",domain_name = "standalone_microblaze_0")

platform = client.get_component(name="platform_MB")
status = platform.build()

comp = client.create_app_component(name="app_component_MB",platform = "$COMPONENT_LOCATION/../platform_MB/export/platform_MB/platform_MB.xpfm",domain = "standalone_microblaze_0")

status = platform.build()

comp = client.get_component(name="app_component_MB")
comp.build()

status = platform.build()

status = platform.build()

status = platform.build()

status = platform.build()

comp.build()

vitis.dispose()

