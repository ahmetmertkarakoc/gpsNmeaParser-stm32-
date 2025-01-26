#ifndef SPEEX_BUFFER_H
#define SPEEX_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

struct RingBuffer_ {
   char  *data;
   int head;
   int rear;
   int size;
};

typedef struct RingBuffer_ RingBuffer;

void ring_buffer_init       (RingBuffer *st, void *buffer, int size);
void ring_buffer_destroy    (RingBuffer *st);

int  ring_buffer_write      (RingBuffer *st, void *data, int len);
void ring_buffer_writeByte  (RingBuffer *st, void *_data);
int  ring_buffer_writezeros (RingBuffer *st, int len);

int  ring_buffer_readByte   (RingBuffer *st, void *_data);
int  ring_buffer_read       (RingBuffer *st, void *data, int len);

int  ring_buffer_get_available(RingBuffer *st);
int  ring_buffer_get_free   (RingBuffer *st);
int  ring_buffer_resize     (RingBuffer *st, int len);
void ring_buffer_flush      (RingBuffer *st);

int  ring_buffer_isEmpty    (RingBuffer *st);
int  ring_buffer_isFull     (RingBuffer *st);

#ifdef __cplusplus
}
#endif

#endif
