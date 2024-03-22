#ifndef __indy__metrics__included__
#define __indy__metrics__included__

#include "indy_types.h"
#include "indy_mod.h"

#ifdef __cplusplus
extern "C" {
#endif


    /// Collect metrics.
    ///
    /// #Returns
    /// Map in the JSON format. Where keys are names of metrics.
    ///
    /// #Errors
    /// Common*
    extern indy_error_t indy_collect_metrics(indy_handle_t command_handle,
                                             void          (*fn)(indy_handle_t command_handle_,
                                                                 indy_error_t    err,
                                                                 const char*   metrics_json)
		                            );

#ifdef __cplusplus
}
#endif

#endif
