/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/apply.hpp>

namespace boost
{

    template <typename... T>
    class variant;

}

namespace brigand
{

    template <typename... T>
    struct variant_wrapper
    {
        using type = typename boost::variant<T...>;
    };

    template <typename L>
    using as_variant = apply<L, variant_wrapper>;

}
