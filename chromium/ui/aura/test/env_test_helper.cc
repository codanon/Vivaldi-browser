// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/aura/test/env_test_helper.h"

namespace aura {
namespace test {

EnvWindowTreeClientSetter::EnvWindowTreeClientSetter(WindowTreeClient* client)
    : previous_client_(Env::GetInstance()->window_tree_client_) {
  SetWindowTreeClient(client);
}

EnvWindowTreeClientSetter::~EnvWindowTreeClientSetter() {
  SetWindowTreeClient(previous_client_);
}

void EnvWindowTreeClientSetter::SetWindowTreeClient(WindowTreeClient* client) {
  Env* env = Env::GetInstance();
  env->window_tree_client_ = client;
  env->in_mus_shutdown_ = client ? false : true;
}

}  // namespace test
}  // namespace aura
