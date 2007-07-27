/**
 * Copyright (C) 2007 Doug Judd (Zvents, Inc.)
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef HYPERTABLE_MASTER_H
#define HYPERTABLE_MASTER_H

#include "Common/Properties.h"
#include "AsyncComm/Comm.h"
#include "AsyncComm/Event.h"
#include "AsyncComm/ResponseCallback.h"

#include "Hypertable/HdfsClient/HdfsClient.h"
#include "Hyperspace/HyperspaceClient.h"

#include "ResponseCallbackGetSchema.h"

using namespace hypertable;

namespace hypertable {

  class Master {
  public:
    Master(Comm *comm, Properties *props);
    ~Master();
    void CreateTable(ResponseCallback *cb, const char *tableName, const char *schemaString);
    void GetSchema(ResponseCallbackGetSchema *cb, const char *tableName);
    bool CreateDirectoryLayout();

  private:
    Comm *mComm;
    bool mVerbose;
    HyperspaceClient *mHyperspace;
    HdfsClient *mHdfsClient;
    atomic_t mLastTableId;
  };

}

#endif // HYPERTABLE_MASTER_H