
#pragma once

#include <brigand/apply.hpp>

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
