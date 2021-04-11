#ifndef SC_FRAME_SINK
#define SC_FRAME_SINK

#include <assert.h>
#include <stdbool.h>

/**
 * Frame sink trait.
 *
 * Component able to receive AVFrames should implement this trait.
 */
struct sc_frame_sink {
    const struct sc_frame_sink_ops *ops;
};

struct sc_frame_sink_ops {
    bool (*open)(struct sc_frame_sink *sink);
    void (*close)(struct sc_frame_sink *sink);
    bool (*push)(struct sc_frame_sink *sink, const AVFrame *frame);
};

#endif
