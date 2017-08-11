#ifndef EXIT_HANDLER_CR_H
#define EXIT_HANDLER_CR_H

#include <exit_handler/exit_handler_intel_x64_eapis.h>

using namespace intel_x64;
using cr3_value_type = intel_x64::cr3::value_type;

class exit_handler_cr : public exit_handler_intel_x64_eapis
{
public:

    /// Default Constructor
    ///
    exit_handler_cr()
    { }

    /// Destructor
    ///
    ~exit_handler_cr() override
    { }

    // cr3 load callback
    //
    // This function implements a simple cr3 load callback.
    // It is a simple monitoring callback, which means it does not modify the value given as parameter.
    //
    // Note: we print only once every 100 times we are called, as the mov to/from cr3 instructions occur often
    // and debug printing is a relatively costly operation,
    // which would have massively influenced performance if done as often as on every callback.
    virtual cr3_value_type cr3_ld_callback(cr3_value_type val) override
    {
        auto static counter = 0;
        counter ++;

        if (counter % 100 == 0)
            bfdebug << "cr3 example load callback hook #" << counter << "; got value: " << std::hex << val << bfendl;

        return val;
    }

    // cr3 store callback
    //
    // This function implements a simple cr3 store callback.
    // It is a simple monitoring callback, which means it does not modify the value given as parameter.
    //
    // Note: we print only once every 100 times we are called, as the mov to/from cr3 instructions occur often
    // and debug printing is a relatively costly operation,
    // which would have massively influenced performance if done as often as on every callback.
    virtual cr3_value_type cr3_st_callback(cr3_value_type val) override
    {
        auto static counter = 0;
        counter ++;

        if (counter % 100 == 0)
            bfdebug << "cr3 example store callback hook #" << counter << "; got value: " << std::hex << val << bfendl;

        return val;
    }

};

#endif