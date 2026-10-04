# 2026-10-04T16:34:27.076084
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis_MB")

platform = client.get_component(name="platform_MB")
status = platform.build()

status = platform.build()

comp = client.get_component(name="app_component_MB")
comp.build()

vitis.dispose()

