/*
 * ringbuf.c
 *
 *  Created on: Jan 10, 2024
 *      Author: teodors.kerimovs
 */


#include "ringbuf.h"

void ring_buffer_setup(ring_buffer_t* rb, uint8_t* buffer, uint32_t size){
	rb->buffer = buffer;
	rb->read_index = 0;
	rb->write_index = 0;
	rb->mask = size - 1;

}

bool ring_buffer_empty(ring_buffer_t* rb){
	return rb->read_index == rb->write_index;
}

bool ring_buffer_write(ring_buffer_t* rb, uint8_t byte){
	uint32_t local_read_index = rb->read_index; // stable local copy
	uint32_t local_write_index = rb->write_index; // stable local copy

	uint32_t next_write_index = (local_write_index + 1) & rb->mask; // wrapping

	if (next_write_index == local_read_index){
		return false;
	}

	rb->buffer[local_write_index] = byte;
	rb->write_index = next_write_index;
	return true;

}

bool ring_buffer_read(ring_buffer_t* rb, uint8_t* byte){
	uint32_t local_read_index = rb->read_index; // stable local copy
	uint32_t local_write_index = rb->write_index; // stable local copy

	if (local_read_index == local_write_index){
		return false; // buffer is empty
	}

	*byte = rb->buffer[local_read_index];
	local_read_index = (local_read_index +1) & rb->mask; // wrapping
	rb->read_index = local_read_index;
	return true;
}
