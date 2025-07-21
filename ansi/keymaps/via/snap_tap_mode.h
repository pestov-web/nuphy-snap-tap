#ifndef SNAP_TAP_MODE_H
#define SNAP_TAP_MODE_H

typedef enum {
    SNAP_TAP_OFF = 0,
    SNAP_TAP_CANCEL,    // отмена (cancellation)
    SNAP_TAP_EXCLUDE    // исключение (exclusion)
} snap_tap_mode_t;

#endif // SNAP_TAP_MODE_H
