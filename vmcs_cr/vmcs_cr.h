#ifndef VMCS_CR_H
#define VMCS_CR_H

#include <vmcs/vmcs_intel_x64_eapis.h>
#include <vmcs/vmcs_intel_x64_16bit_control_fields.h>
#include <vmcs/vmcs_intel_x64_32bit_control_fields.h>

using namespace intel_x64;
using namespace vmcs;

class vmcs_cr : public vmcs_intel_x64_eapis
{
public:

    /// Default Constructor
    ///
    vmcs_cr() = default;

    /// Destructor
    ///
    ~vmcs_cr() override  = default;

    /// Write Fields
    ///
    /// This functions is provided by the VMCS class as a means to
    /// extend the existing VMCS setup with custom logic. In this
    /// example, we enable catching mov to cr3.
    ///
    void
    write_fields(gsl::not_null<vmcs_intel_x64_state *> host_state,
                 gsl::not_null<vmcs_intel_x64_state *> guest_state) override
    {
        bfdebug << " enabling mov to cr3 exits" << bfendl;

        // Before we setup cr, we let the existing VMCS set itself up. This way
        // whatever changes we are making are done on top of the default setup.
        vmcs_intel_x64_eapis::write_fields(host_state, guest_state);

        vmcs_intel_x64_eapis::enable_cr3_load_hook();
        vmcs_intel_x64_eapis::enable_cr3_store_hook();
    }
};

#endif