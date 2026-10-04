# 2026-10-04T16:47:05.861813
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis_MB")

platform = client.get_component(name="platform_MB")
status = platform.build()

comp = client.get_component(name="app_component_MB")
comp.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

comp.build()

