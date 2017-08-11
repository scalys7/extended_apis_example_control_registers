# Bareflank Hypervisor Control Registers Access Hooks Example

## Description

This example demonstrates how to extend the Bareflank hypervisor to use
the APIs for hooking store/load access to the control registers. For more information on how Bareflank
extensions work, please see the following:

[API Documentation](http://bareflank.github.io/hypervisor/html/)

## Compilation / Usage

To setup our extension, run the following (assuming Linux):

```
cd ~/
git clone https://github.com/Bareflank/hypervisor.git
git clone https://github.com/Bareflank/extended_apis.git
git clone https://github.com/Bareflank/extended_apis_example_control_registers.git
cd ~/hypervisor

./tools/scripts/setup-<xxx>.sh --no-configure
sudo reboot

cd ~/
mkdir build
cd ~/build

~/hypervisor/configure -m ~/hypervisor_example_cr_access_hooks/bin/cr_access_hooks.modules -e ~/hypervisor_example_cr_access_hooks
make
```

To test out our extended version of Bareflank, all we need to do is run the
make shortcuts as usual:

```
make driver_load
make quick

make status
make dump

make stop
make driver_unload
```

The debug output should be something like:
> DEBUG:  enabling mov to cr3 exits
>
>DEBUG: success: host os is now in a vm on vcpuid = 0
>
>DEBUG:  enabling mov to cr3 exits
>
>DEBUG: success: host os is now in a vm on vcpuid = 1
>
>DEBUG: cr3 example store callback hook #100; got value: 63a37000
>
>DEBUG: cr3 example store callback hook #c8; got value: 6fab4000
>
>DEBUG: cr3 example load callback hook #3e8; got value: 8fe8f000
>
>DEBUG: cr3 example store callback hook #12c; got value: 8fe8f000
>
>DEBUG: cr3 example store callback hook #190; got value: b5fc3000
>
>DEBUG: cr3 example store callback hook #1f4; got value: 63a61000
>
>DEBUG: cr3 example load callback hook #7d0; got value: 8fe8f000
>
>DEBUG: cr3 example store callback hook #258; got value: 6fb14000
