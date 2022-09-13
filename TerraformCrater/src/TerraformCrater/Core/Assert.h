#pragma once

#include "Base.h"
#include "Log.h"

#ifdef TC_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define TC_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { TC##type##ERROR(msg, __VA_ARGS__); TC_DEBUGBREAK(); } }
#define TC_INTERNAL_ASSERT_WITH_MSG(type, check, ...) TC_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define TC_INTERNAL_ASSERT_NO_MSG(type, check) TC_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", TC_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define TC_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define TC_INTERNAL_ASSERT_GET_MACRO(...) TC_EXPAND_MACRO( TC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, TC_INTERNAL_ASSERT_WITH_MSG, TC_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define TC_ASSERT(...) TC_EXPAND_MACRO( TC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define TC_CORE_ASSERT(...) TC_EXPAND_MACRO( TC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define TC_ASSERT(...)
#define TC_CORE_ASSERT(...)
#endif