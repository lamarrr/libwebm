// Copyright (c) 2012 The WebM project authors. All Rights Reserved.
//
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file in the root of the source
// tree. An additional intellectual property rights grant can be found
// in the file PATENTS.  All contributing project authors may
// be found in the AUTHORS file in the root of the source tree.

#ifndef MKVMUXER_MKVWRITER_HPP_
#define MKVMUXER_MKVWRITER_HPP_

#include <stdio.h>

#include "mkvmuxer/mkvmuxer.hpp"
#include "mkvmuxer/mkvmuxertypes.hpp"

namespace libwebm {
namespace mkvmuxer {

// Default implementation of the IMkvWriter interface on Windows.
class MkvWriter : public IMkvWriter {
 public:
  MkvWriter();
  explicit MkvWriter(FILE* fp);
  virtual ~MkvWriter();

  // IMkvWriter interface
  virtual int64_t Position() const;
  virtual int32_t Position(int64_t position);
  virtual bool Seekable() const;
  virtual int32_t Write(const void* buffer, uint32_t length);
  virtual void ElementStartNotify(uint64_t element_id, int64_t position);

  // Creates and opens a file for writing. |filename| is the name of the file
  // to open. This function will overwrite the contents of |filename|. Returns
  // true on success.
  bool Open(const char* filename);

  // Closes an opened file.
  void Close();

 private:
  // File handle to output file.
  FILE* file_;
  bool writer_owns_file_;

  LIBWEBM_DISALLOW_COPY_AND_ASSIGN(MkvWriter);
};

}  // namespace mkvmuxer
}  // namespace libwebm

#endif  // MKVMUXER_MKVWRITER_HPP_