/*
 * Copyright (c) 2017, Circonus, Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name Circonus, Inc. nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NOIT_CHECK_LOG_H
#define NOIT_CHECK_LOG_H

#include <mtev_defines.h>

/*!
  \fn noit_check_log_bundle_metric_flatbuffer_serialize(struct timeval *whence, const char *check_uuid, const char *check_name, int account_id, metric_t *m,size_t* out_size)
  \brief Create a MetricBatch flatbuffer representing a single record
  \return The flatbuffer bytes, size is returned in 'out_size'
*/
API_EXPORT(void *)
noit_check_log_bundle_metric_flatbuffer_serialize(struct timeval *whence, const char *check_uuid,
                                                  const char *check_name, int account_id, metric_t *m,
                                                  size_t* out_size);

/*!
  \fn noit_check_log_bundle_metric_flatbuffer_serialize_check(struct timeval *whence, const char *check_uuid, const char *check_name, int account_id, metric_t *m, size_t metric_count, size_t* out_size)
  \brief Create a MetricBatch flatbuffer representing 'metric_count' records
  \return The flatbuffer bytes, size is returned in 'out_size'
*/
API_EXPORT(void *)
noit_check_log_bundle_metric_flatbuffer_serialize_check(struct timeval *whence, const char *check_uuid,
                                                        const char *check_name, int account_id, metric_t *m, size_t metric_count,
                                                        size_t* out_size);


/*!
  \fn noit_check_log_create_flatbuffer_builder(void)
  \brief Create a MetricList flatbuffer builder which we can append metric_t's to
  \return The flatbuffer builder handle
*/
API_EXPORT(void *)
noit_check_log_create_flatbuffer_builder(void);

/*!
  \fn noit_check_log_finalize_flatbuffer_builder(void *builder, size_t *out_size)
  \brief Serialize and output the bytes for this flatbuffer based on what has been added so far
  \return The flatbuffer bytes, size is returned in 'out_size'

  The builder will be destroyed after this call.
*/
API_EXPORT(void *)
noit_check_log_finalize_flatbuffer_builder(void *builder, size_t *out_size);

/*!
  \fn noit_check_add_to_flatbuffer(void *builder, struct timeval *whence, const char *check_uuid, const char *check_name, int account_id, metric_t *m)
  \brief Add a record to the MetricList flatbuffer
*/
API_EXPORT(void)
noit_check_log_add_to_flatbuffer(void *builder, struct timeval *whence, const char *check_uuid,
                                 const char *check_name, int account_id, metric_t *m);



#endif /* NOIT_CHECK_LOG_H */
