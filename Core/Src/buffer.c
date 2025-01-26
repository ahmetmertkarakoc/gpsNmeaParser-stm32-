#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "string.h"
#include "buffer.h"

void ring_buffer_init(RingBuffer *st, void *buffer, int size)
{
   st->head = 0;
   st->rear = 0;
   st->data = buffer;
   st->size = size;
}

void ring_buffer_destroy(RingBuffer *st)
{
   // Eğer dinamik olarak bellek ayırıyorsan free() vs. yapılabilir
}

// ---------------------------------------------------
// Yeni eklediğin ring_buffer_isEmpty
// ---------------------------------------------------
int ring_buffer_isEmpty(RingBuffer *st)
{
    // Boş olma durumu: head == rear
    return (st->head == st->rear) ? 1 : 0;
}

// ---------------------------------------------------
// Yeni eklediğin ring_buffer_isFull
// ---------------------------------------------------
int ring_buffer_isFull(RingBuffer *st)
{
    // Buffer doluysa head, rear'ın 1 adım önündedir
    return ((st->head + 1) % st->size == st->rear) ? 1 : 0;
}

int ring_buffer_write(RingBuffer *st, void *_data, int len)
{
    int ret = 0;
    while (len--)
    {
        ring_buffer_writeByte(st, _data++);
        ret++;
    }
    return ret;
}

void ring_buffer_writeByte(RingBuffer *st, void *_data)
{
    st->data[st->head] = *((char*)_data);
    st->head++;
    if (st->head >= st->size)
        st->head = 0;
    if (st->head == st->rear)
    {
        st->rear++;
        if (st->rear >= st->size)
            st->rear = 0;
    }
}

int ring_buffer_writezeros(RingBuffer *st, int len)
{
    // İhtiyacın yoksa boş bırak
    return 0;
}

int ring_buffer_readByte(RingBuffer *st, void *_data)
{
    if (st->rear == st->head)
        return 0;

    *((char*)_data) = st->data[st->rear];
    st->rear++;
    if (st->rear >= st->size)
        st->rear = 0;

    return 1;
}

int ring_buffer_read(RingBuffer *st, void *_data, int len)
{
    int ret = 0;
    while (len--)
    {
        if (!ring_buffer_readByte(st, _data++))
            break;
        ret++;
    }
    return ret;
}

int ring_buffer_get_available(RingBuffer *st)
{
    int result = st->head - st->rear;
    if (result < 0)
        result += st->size;
    return result;
}

int ring_buffer_get_free(RingBuffer *st)
{
    int count = st->size - ring_buffer_get_available(st);
    return count;
}

int ring_buffer_resize(RingBuffer *st, int len)
{
   // İhtiyacına göre implemente et
   return 0;
}

void ring_buffer_flush(RingBuffer *st)
{
   st->head = 0;
   st->rear = 0;
}
