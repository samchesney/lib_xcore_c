// Copyright (c) 2016, XMOS Ltd, All rights reserved

#ifndef __xcore_c_eventerrupt_internal_h__
#define __xcore_c_eventerrupt_internal_h__

#if !defined(__XC__) || defined(__DOXYGEN__)

#include "xcore_c_eventerrupt_defines.h"

#ifndef EVENTERRUPT_MAX_HANDLER_FUNCTIONS
/**
 * The default maximum number of event handler functions. This needs to be
 * a compile-time constant as space needs to be allocated for the handler data.
 */
#define EVENTERRUPT_MAX_HANDLER_FUNCTIONS 20
#endif

/** The typedef for all function event and interrupt handlers.
 *
 * The ID of the resource that triggered the event or interrupt is passed to the
 * handler along with the user data registered with that resource.
 */
typedef void (*eventerrupt_handler)(resource, void*);

/** The structure to register event and interrupt function handlers
 */
typedef struct eventerrupt_handler_function_state {
  resource owner;
  event_handler handler;
  void *data;
} eventerrupt_handler_function_state;

/* Compile time check to ensure the SIZEOF_EVENTERRUPT_HANDLER_FUNCTION_STATE
 * define is always set correctly
 */
_Static_assert(((SIZEOF_EVENTERRUPT_HANDLER_FUNCTION_STATE * sizeof(int)) ==
                sizeof(eventerrupt_handler_function_state)),
               "SIZEOF_EVENTERRUPT_HANDLER_FUNCTION_STATE define is incorrect");

#endif // __XC__

#endif // __xcore_c_eventerrupt_internal_h__
