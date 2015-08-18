// Copyright 2015 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <mongocxx/config/prelude.hpp>

#include <mongocxx/pool.hpp>

#include <mongoc.h>
#include <utility>

#include <mongocxx/private/libmongoc.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN

class pool::impl {
   public:
    impl(mongoc_client_pool_t* pool, stdx::optional<options::ssl> ssl_opts)
        : client_pool_t(pool), ssl_options(std::move(ssl_opts)) {
    }

    ~impl() {
        libmongoc::client_pool_destroy(client_pool_t);
    }

    mongoc_client_pool_t* client_pool_t;
    stdx::optional<options::ssl> ssl_options;
};  // class impl

MONGOCXX_INLINE_NAMESPACE_END
};  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>
