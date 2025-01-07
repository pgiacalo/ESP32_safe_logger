This project fixes the annoying ESP32 compiler error that often occurs when logging or printing a message and value.

        error: format '%u' expects argument of type 'unsigned int', but argument 6 has type 'uint32_t'

To avoid the format/type errors, call the logging functions provided in safe_logger.h (rather than calling print() or ESP_LOGx() functions):

     LOG_INFO(tag, msg, val)
     LOG_WARN(tag, msg, val)
     LOG_ERROR(tag, msg, val)
     LOG_DEBUG(tag, msg, val)

These are wrapper functions that will correctly handle any built-in val type and thereby avoid the compiler error. 
