/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/apply.hpp>

namespace brigand
{
  template <typename... T>
  struct tuple_wrapper
  {
      using type = typename std::tuple<T...>;
  };

  template <typename L>
  using as_tuple = apply<L, tuple_wrapper>;
}
