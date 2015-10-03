/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#ifndef BRIGAND_HPP_INCLUDED
#define BRIGAND_HPP_INCLUDED







#include <type_traits>

namespace brigand
{
    template <class... T> struct list {};

    template<typename T, T... Values>
  using integral_list = brigand::list< std::integral_constant<T,Values>...>;

    using empty_list = brigand::list<>;
}

#include <type_traits>

namespace brigand
{
  template <bool B>
  using bool_ = std::integral_constant<bool, B>;

  using true_ = bool_<true>;
  using false_ = bool_<false>;
}

#include <type_traits>

namespace brigand
{
  template<typename T> struct type_ { using type = T; };

  template<typename T> using type_from = typename T::type;
}

namespace brigand
{
    template <typename First, typename Second>
    struct pair
    {
        using first_type = First;
        using second_type = Second;
    };

}

namespace brigand
{
            struct no_such_type_ {};
}

namespace brigand
{
namespace detail
{
    template <class... T>
    struct map_impl;

    template <>
    struct map_impl<>
    {
        template <typename U>
        static no_such_type_ at(U);
    };

        template <class T0>
    struct map_impl<T0>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1>
    struct map_impl<T0, T1>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2>
    struct map_impl<T0, T1, T2>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3>
    struct map_impl<T0, T1, T2, T3>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4>
    struct map_impl<T0, T1, T2, T3, T4>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5>
    struct map_impl<T0, T1, T2, T3, T4, T5>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);
        static typename T7::second_type at(type_<typename T7::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };


    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class... T>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7, T...>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);
        static typename T7::second_type at(type_<typename T7::first_type>);

        template <typename U>
        static decltype(map_impl<T...>::at(U{})) at(U);
    };

            template<class... Ts>
    struct make_map : type_<typename Ts::first_type>... {
      using type = map_impl<Ts...>;
    };
}
    template<class... Ts>
    using map = typename detail::make_map<Ts...>::type;

    template <typename M, typename K>
    using lookup = decltype(M::at(type_<K>{}));
}

#include <type_traits>

namespace brigand
{
  template <typename A>
  struct next : std::integral_constant < typename A::value_type, A::value + 1 > {};
}

namespace brigand
{
namespace detail
{
  template<class Start, unsigned N, template<class> class Next, class List, bool = (N > 8)>
  struct make_sequence_impl;

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 0, Next, List<E...>, false>
  {
    using type = List<E...>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 1, Next, List<E...>, false>
  {
    using type = List<E..., Start>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 2, Next, List<E...>, false>
  {
    using type = List<E..., Start, Next<Start>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 3, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using type = List<E..., Start, t1, Next<t1>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 4, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using type = List<E..., Start, t1, t2, Next<t2>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 5, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using type = List<E..., Start, t1, t2, t3, Next<t3>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 6, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using type = List<E..., Start, t1, t2, t3, t4, Next<t4>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 7, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, Next<t5>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 8, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using t6 = Next<t5>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, Next<t6>>;
  };

  template<class Start, unsigned N, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, N, Next, List<E...>, true>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using t6 = Next<t5>;
    using t7 = Next<t6>;
    using type = typename make_sequence_impl<Next<t7>, N-8, Next, List<E..., Start, t1, t2, t3, t4, t5, t6, t7>>::type;
  };
}

  template<class Start, unsigned N, template<class> class Next = next, template<class...> class List = list>
  using make_sequence = typename detail::make_sequence_impl<Start, N, Next, List<>>::type;
}
#include <type_traits>

namespace brigand
{
  template <typename A>
  struct prev : std::integral_constant < typename A::value_type, A::value - 1 > {};
}

namespace brigand
{
    template<class T, T Start, T Stop>
    using range = make_sequence<std::integral_constant<T, Start>, Stop - Start>;

    template<class T, T Start, T Stop>
    using reverse_range = make_sequence<std::integral_constant<T, Start>, Start - Stop, prev>;
}

namespace brigand
{
  namespace detail
  {
    template<typename T> struct element_at;

    template<typename T> struct ignore { template<typename U> ignore(U&&); };

    template<template<typename...> class L, typename... N>
    struct element_at<L<N...>>
    {
      template<typename T> type_<T> operator()(ignore<N>..., type_<T>, ...);
    };

    template<std::size_t N, typename Seq> struct at_impl;

    template<std::size_t N, template<typename...> class L, typename... Ts >
    struct at_impl<N,L<Ts...>>
    {
      using base = decltype(element_at<brigand::range<int,0,N>>()(brigand::type_<Ts>()...));
      using type = typename base::type;
    };
  }

  template <class L, int Index>
  using at_c = typename detail::at_impl<Index, L>::type;

namespace detail
{
    template <typename T>
    struct has_at_method
    {
        struct dummy {};
        template <typename C, typename P>
        static auto test(P * p) -> decltype(C::at(*p), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };

    template <class L, typename Index, bool>
    struct at_dispatch
    {
        using type = at_c<L, Index::value>;
    };

    template <class L, typename Index>
    struct at_dispatch<L, Index, true>
    {
        using type = lookup<L, Index>;
    };
}

    template <class Seq, typename K>
    using at = typename detail::at_dispatch<Seq, K, detail::has_at_method<Seq>::value>::type;
}


namespace brigand
{
  template<std::size_t Index> struct placeholders;

  namespace detail
  {
    template<typename T, typename List>
    struct substitute_impl
    {
      using type = T;
    };

    template<template<class...> class T, typename... Ts, typename List>
    struct substitute_impl<T<Ts...>,List>
    {
      using type = T<typename substitute_impl<Ts,List>::type...>;
    };

    template<std::size_t Index, typename List>
    struct substitute_impl<placeholders<Index>,List>
    {
      using type = brigand::at_c<List,Index>;
    };
  }

  template<typename T, typename List>
  using substitute = typename detail::substitute_impl<T,List>::type;
}

namespace brigand
{
  template<std::size_t Index> struct placeholders {};

  using _  = placeholders<0>;
  using _1 = placeholders<0>;
  using _2 = placeholders<1>;
  using _3 = placeholders<2>;
  using _4 = placeholders<3>;
  using _5 = placeholders<4>;
  using _6 = placeholders<5>;
  using _7 = placeholders<6>;
  using _8 = placeholders<7>;
  using _9 = placeholders<8>;

  namespace detail
  {
    template <template <class> class T>
    struct unary_placeholder_adaptor
    {
      template <class P> struct apply : T<P> {};
    };

    template <template <class, class> class T>
    struct binary_placeholder_adaptor
    {
      template <class P1, class P2> struct apply : T<P1, P2> {};
    };
  }
}

namespace brigand
{
  template<typename... T> struct is_placeholder;

  template<typename T> struct is_placeholder<T> : brigand::false_ {};

  template<template<class...>class T,typename... Ts>
  struct is_placeholder<T<Ts...>> : is_placeholder<Ts...> {};

  template<std::size_t I>
  struct is_placeholder< brigand::placeholders<I>> : brigand::true_ {};

  template <bool...> struct checks_ {};

  template<typename T, typename U, typename... Ts>
  struct is_placeholder<T,U,Ts...>
        : bool_ < !std::is_same < checks_ < true
                                          , !is_placeholder<T>::value, !is_placeholder<U>::value
                                          , !is_placeholder<Ts>::value...
                                          >
                                , checks_ < !is_placeholder<T>::value, !is_placeholder<U>::value
                                          , !is_placeholder<Ts>::value...
                                          , true
                                          >
                                >::value
                >
  {};
}

namespace brigand
{
  template<typename T, typename R = void > struct has_type
  {
    using type = R;
  };
}

namespace brigand
{
  namespace detail
  {
    template<typename T, typename If = void> struct eval_;

    template<typename T> struct recurse { using type = T; };

    template<template<class...> class U, typename... T> struct recurse<U<T...>>
    {
      template<typename X> using get = typename eval_<X>::type;
      using type = U<get<T>...>;
    };

    template<typename T, typename If> struct eval_
    {
      using type = typename recurse<T>::type;
    };

    template<typename T> struct eval_<T,typename has_type<typename T::type>::type>
    {
      using type = typename recurse<T>::type::type;
    };

    template<typename F, typename Xs, typename If = void> struct lambda_impl;

        template< template<class...> class F, typename... An
            , template<class...> class L, typename... X
            >
    struct lambda_impl< F<An...>, L<X...>
                      , typename std::enable_if<is_placeholder<An...>::value>::type
                      >
    {
      using base = F<substitute<An,L<X...>>...>;
      using type = typename eval_<base>::type;
    };

        template< typename F
            , template<class...> class L, typename... X
            , typename If
            >
    struct lambda_impl<F, L<X...>, If> : F::template apply<X...> {};
  }

  template<typename F> struct lambda
  {
    template<typename... X> struct apply : detail::lambda_impl<F, brigand::list<X...>> {};
  };
}

namespace brigand
{
  namespace detail
  {
    template<typename Lambda, typename Args> struct apply;

    template<typename Lambda, template<class...> class List, typename... Args>
    struct apply < Lambda, List<Args...> >
    {
      using type = typename Lambda::template apply<Args...>::type;
    };
  }

  template<typename Lambda, typename... Args>
  using apply = typename detail::apply<lambda<Lambda>,brigand::list<Args...>>::type;
}

namespace brigand
{
  namespace detail
  {

  template <typename Functor, typename Sequence>
  struct unary_transform_impl;

        template< typename Functor
            , template<class...> class Sequence, typename... T
            >
  struct unary_transform_impl<Functor, Sequence<T...>>
    {
      using type = Sequence< brigand::apply<Functor,T>... >;
    };

  template<typename Functor, typename Sequence1, typename Sequence2>
  struct binary_transform_impl;

        template< typename Functor
            , template<class...> class Sequence1, typename... T1
            , template<class...> class Sequence2, typename... T2
            >
  struct binary_transform_impl<Functor, Sequence1<T1...>, Sequence2<T2...>>
    {
      static_assert ( sizeof...(T1) == sizeof...(T2)
                    , "The arguments of transform should be of the same size"
                    );

      using type = Sequence1< brigand::apply<Functor,T1,T2>... >;
  };

  template <std::size_t Selector, typename Sequence1, typename Functor, typename Sequence2 = void>
  struct transform_selector;

  template <typename Sequence1, typename Functor>
  struct transform_selector <0, Sequence1, Functor, void>
  {
    using type = typename unary_transform_impl<Functor, Sequence1>::type;
  };

  template <typename Sequence1, typename Sequence2, typename Functor>
  struct transform_selector<1, Sequence1, Sequence2, Functor>
  {
    using type = typename binary_transform_impl<Functor, Sequence1, Sequence2>::type;
  };

  }

    template<typename Sequence1, typename OpSeq1, typename... OpSeq2>
  using transform = typename detail::transform_selector<sizeof...(OpSeq2), Sequence1, OpSeq1, OpSeq2...>::type;

}

namespace brigand
{

    template <typename T>
    struct make_integral : std::integral_constant <typename T::value_type, T::value> {};

    template <typename L>
    using as_integral_list = transform<L, make_integral<brigand::_1>>;

}


namespace brigand
{
  namespace detail
  {
    template <class A, template<class...> class B> struct wrap_impl;

    template<template<class...> class A, class... T, template<class...> class B>
    struct wrap_impl<A<T...>, B>
    {
      using type = B<T...>;
    };
  }

  template<class A, template<class...> class B>
  using wrap = typename detail::wrap_impl<A, B>::type;
}

namespace brigand
{
  template <typename... T>
  using list_wrapper = typename brigand::list<T...>;

  template <typename L>
  using as_list = wrap<L, list_wrapper>;
}

#include <utility>

namespace brigand
{
  template <typename... T>
  struct pair_wrapper_
  {
    static_assert (sizeof...(T) == 2
                  , "as_pair requires a type list of exactly two types"
                  );

        using type = no_such_type_;
  };

  template <typename T, typename U>
  struct pair_wrapper_<T,U>
  {
      using type = std::pair<T,U>;
  };

  template <typename... T>
  using pair_wrapper = typename pair_wrapper_<T...>::type;

  template <typename L>
  using as_pair = wrap<L, pair_wrapper>;
}

#include <tuple>

namespace brigand
{
  template <typename... T>
  using tuple_wrapper = typename std::tuple<T...>;

  template <typename L>
  using as_tuple = wrap<L, tuple_wrapper>;
}

#if !defined(BRIGAND_LEAN_AND_MEAN)

#include <boost/fusion/container/vector/vector_fwd.hpp>
#include <boost/fusion/container/deque/deque_fwd.hpp>
#include <boost/fusion/container/list/list_fwd.hpp>
#include <boost/fusion/container/set/set_fwd.hpp>

namespace brigand
{
  template <typename... T>
  using fusion_vector_wrapper = boost::fusion::vector<T...>;

  template <typename... T>
  using fusion_list_wrapper = boost::fusion::list<T...>;

  template <typename... T>
  using fusion_deque_wrapper = boost::fusion::deque<T...>;

  template <typename... T>
  using fusion_set_wrapper = boost::fusion::set<T...>;

  template <typename L> using as_fusion_vector = wrap<L, fusion_vector_wrapper>;
  template <typename L> using as_fusion_deque  = wrap<L, fusion_deque_wrapper>;
  template <typename L> using as_fusion_list   = wrap<L, fusion_list_wrapper>;
  template <typename L> using as_fusion_set    = wrap<L, fusion_set_wrapper>;
}

#include <boost/variant.hpp>

namespace brigand
{
  template <typename... T>
  using variant_wrapper = typename boost::variant<T...>;

  template <typename L>
  using as_variant = wrap<L, variant_wrapper>;
}
#endif




namespace brigand { namespace detail
{
    struct non_null
  {
    template<typename Args> struct apply : bool_< Args::value != 0> {};
  };
} }
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template <bool...> struct bools_ {};
    template< typename Sequence, typename Predicate, typename... Ts> struct all_impl;

    template<typename P, typename T> using invoked = brigand::apply<P,T>;

    template< template<class...> class Sequence, typename Predicate, typename... Ts>
    struct  all_impl<Sequence<Ts...>,Predicate>
          : std::is_same< bools_<true, invoked<Predicate,Ts>::value...>
                        , bools_<invoked<Predicate,Ts>::value..., true>
                        >
    {};
  }

    template<typename Sequence, typename Predicate = detail::non_null>
  using all = typename detail::all_impl<Sequence,Predicate>::type;
}



namespace brigand
{
  namespace detail
  {
    template<typename Sequence, typename Pred> struct none_impl
    {
      struct nope
      {
        template<typename T> struct apply
        {
          using that = brigand::apply<Pred,T>;
          using type = bool_<!that::value>;
        };
      };

      using type = all<Sequence,nope>;
    };
  }

    template< typename Sequence, typename Predicate = detail::non_null>
  using none = typename detail::none_impl<Sequence,Predicate>::type;
}

namespace brigand
{
  namespace detail
  {
    template< typename Sequence, typename Predicate >
    struct any_impl : bool_<!none<Sequence,Predicate>::value> {};
  }

    template<typename Sequence, typename Predicate = detail::non_null>
  using any = typename detail::any_impl<Sequence,Predicate>::type;
}
#include <type_traits>

namespace brigand
{
  template<class... T>
  using count = std::integral_constant<std::size_t, sizeof...(T)>;
}



namespace brigand { namespace detail
{
    template< typename Predicate, class Sequence>
  struct find_if_impl
  {
    using type = Sequence;
  };

    template<typename Status, typename Predicate, class Sequence>
  struct find_if_shortcut;

    template< typename Predicate
          , template<class...> class Sequence
          , typename H, typename... T
          >
  struct  find_if_impl<Predicate,Sequence<H,T...>>
        : find_if_shortcut<brigand::apply<Predicate,H>, Predicate, Sequence<H,T...> >
  {};

    template<typename Predicate, class Sequence>
  struct find_if_shortcut<true_,Predicate,Sequence>
  {
    using type = Sequence;
  };

    template< typename Predicate
          , template<class...> class Sequence
          , typename H, typename... T
          >
  struct  find_if_shortcut<false_,Predicate, Sequence<H,T...>>
        : find_if_impl<Predicate,Sequence<T...>>
  {};
} }

#include <type_traits>
#include <cstddef>

namespace brigand
{
  template<char V>      using char_       = std::integral_constant<char     , V>;
  template<short V>     using short_      = std::integral_constant<short    , V>;
  template<int V>       using int_        = std::integral_constant<int      , V>;
  template<long V>      using long_       = std::integral_constant<long     , V>;
  template<long long V> using long_long_  = std::integral_constant<long long, V>;

  template<unsigned char V>      using uchar_       = std::integral_constant<unsigned char     , V>;
  template<unsigned short V>     using ushort_      = std::integral_constant<unsigned short    , V>;
  template<unsigned int V>       using uint_        = std::integral_constant<unsigned int      , V>;
  template<unsigned long V>      using ulong_       = std::integral_constant<unsigned long     , V>;
  template<unsigned long long V> using ulong_long_  = std::integral_constant<unsigned long long, V>;

  template<std::size_t V>     using size_t    = std::integral_constant<std::size_t, V>;
  template<std::ptrdiff_t V>  using ptrdiff_t = std::integral_constant<std::ptrdiff_t, V>;
}

namespace brigand
{
  template<class L> using size = wrap<L, count>;
}


namespace brigand
{
  template <class... L> struct append_impl;

  template <class... L> using append = typename append_impl<L...>::type;

  template <> struct append_impl<>
  {
    using type = brigand::empty_list;
  };

  template<template<class...> class L, class... T>
  struct append_impl<L<T...>>
  {
    using type = L<T...>;
  };

  template<template<class...> class L1, class... T1, template<class...> class L2, class... T2, class... Lr>
  struct append_impl<L1<T1...>, L2<T2...>, Lr...>
  {
    using type = append<L1<T1..., T2...>, Lr...>;
  };
}

namespace brigand
{
namespace detail
{

    template <template <class...> class L, class First, class... R>
    struct reverse_elements
    {
        using head = L<First>;
        using tail = typename reverse_elements<L, R...>::type;
        using type = typename brigand::append<tail, head>;
    };

    template <template <class...> class L, class T0>
    struct reverse_elements<L, T0>
    {
        using type = L<T0>;
    };

        template <template <class...> class L, class T0, class T1>
    struct reverse_elements<L, T0, T1>
    {
        using type = L<T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2>
    struct reverse_elements<L, T0, T1, T2>
    {
        using type = L<T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3>
    struct reverse_elements<L, T0, T1, T2, T3>
    {
        using type = L<T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4>
    struct reverse_elements<L, T0, T1, T2, T3, T4>
    {
        using type = L<T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5>
    {
        using type = L<T5, T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5, T6>
    {
        using type = L<T6, T5, T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5, T6, T7>
    {
        using type = L<T7, T6, T5, T4, T3, T2, T1, T0>;
    };

    template <class L, class Count = brigand::size<L>> struct reverse_impl;

    template<template<class...> class L, class... U, class Count>
    struct reverse_impl<L<U...>,Count>
    {
        using type = typename reverse_elements<L, U...>::type;
    };

    template<template<class...> class L, class... U>
    struct reverse_impl<L<U...>, brigand::size_t<0>>
    {
        using type = L<U...>;
    };

}

    template <typename L>
    using reverse = typename detail::reverse_impl<L>::type;
}

namespace brigand
{
    template<typename Sequence, typename Predicate = detail::non_null>
  using find = typename detail::find_if_impl<Predicate, Sequence>::type;

    template<typename Sequence, typename Predicate = detail::non_null>
  using reverse_find = reverse< find< reverse<Sequence>, Predicate> >;

    template<typename Sequence, typename Predicate = detail::non_null>
  using not_found = typename std::is_same<find<Sequence,Predicate>,empty_list>::type;

      template<typename Sequence, typename Predicate = detail::non_null>
  using found = bool_<!std::is_same<find<Sequence,Predicate>,empty_list>::value>;
}


namespace brigand { namespace detail
{
    template<template<class,class> class Functor, class State, class Sequence>
  struct fold_impl
  {
    using type = State;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence, typename T
          >
  struct fold_impl<Functor, State, Sequence<T>>
  {
    using type = Functor<State,T>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1
          >
  struct fold_impl<Functor, State, Sequence<T0,T1>>
  {
    using state0 = Functor<State,T0>;
    using type   = Functor<state0, T1>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using type   = Functor<state1, T2>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using type   = Functor<state2, T3>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3, typename T4
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using type   = Functor<state3, T4>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using type   = Functor<state4, T5>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          , typename T6
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using type   = Functor<state5, T6>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          , typename T6, typename T7
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6,T7>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using state6 = Functor<state5, T6>;
    using type   = Functor<state6, T7>;
  };

    template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3
          , typename T4, typename T5, typename T6, typename T7
          , class... T
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6,T7,T...>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using state6 = Functor<state5, T6>;
    using state7 = Functor<state6, T7>;
    using type = typename fold_impl<Functor,state7, Sequence<T...>>::type;
  };
} }

namespace brigand
{
    template <class Sequence, class State, template<class,class> class Functor>
  using fold = typename detail::fold_impl<Functor, State, Sequence>::type;
}

#include <initializer_list>
#include <functional>

namespace brigand
{
  template<class F, class...Ts> F for_each_args(F f, Ts&&...a)
  {
    return (void)std::initializer_list<int>{((void)std::ref(f)(static_cast<Ts&&>(a)),0)...}, f;
  }
}

namespace brigand
{
  namespace detail
  {
    template<template<class...> class List, typename... Elements, typename Functor>
    Functor for_each_impl( List<Elements...>&&, Functor f )
    {
      return for_each_args( f, type_<Elements>()... );
    }
  }

  template<typename List, typename Functor> Functor for_each( Functor f )
  {
    return detail::for_each_impl( List{}, f );
  }
}


namespace brigand
{
namespace detail
{
  template<class Ints, class...T>
  struct is_set_impl
  {
    template<class U>
    static std::true_type is_set(U);

    static std::true_type is_set();
  };

  template<class, class T>
  struct unique_x_t
  { operator type_<T> (); };

  template<class... T>
  struct unique_set : T... {};

  template<class Int, class... Ints, class L, class... R>
  struct is_set_impl<list<Int, Ints...>, L, R...>
  {
    template<class U, class = decltype(static_cast<type_<U>>(unique_set<unique_x_t<Int, L>, unique_x_t<Ints, R>...>()))>
    static std::false_type is_set(type_<U>);

    template<class U>
    static decltype(is_set_impl<list<Ints...>, R...>::is_set(type_<L>()))
    is_set(U);

    static decltype(is_set_impl<list<Ints...>, R...>::is_set(type_<L>()))
    is_set(...);
  };
}

  template <class... T>
  using is_set = decltype(detail::is_set_impl<make_sequence<uint_<0>, sizeof...(T)>, T...>::is_set());
}

#include <type_traits>

namespace brigand
{
namespace detail
{
  template<class L>
  struct clear_impl;

  template<template<class...> class L, class... Ts>
  struct clear_impl<L<Ts...>>
  {
    using type = L<>;
  };
}

  template<class L>
  using clear = typename detail::clear_impl<L>::type;
}
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template< class L1, typename Pred, class L2 = clear<L1>>
    struct remove_if_impl
    {
      using type = L2;
    };

    template< class L1, typename Pred, class L2, bool >
    struct remove_if_shortcut;

    template< template<class...> class L1, class T, class... Ts,
              typename Pred,
              template<class...> class L2, class... Us >
    struct remove_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, true>
    : remove_if_impl<L1<Ts...>, Pred, L2<Us...>>
    {};

    template< template<class...> class L1, class T, class... Ts,
              typename Pred,
              template<class...> class L2, class... Us >
    struct remove_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, false>
    : remove_if_impl<L1<Ts...>, Pred, L2<Us..., T>>
    {};

    template<typename Pred, typename T> using pred = brigand::apply<Pred,T>;

    template< template<class...> class L1, class T, class... Ts,
              typename Pred, class L2 >
    struct remove_if_impl<L1<T, Ts...>, Pred, L2>
    : remove_if_shortcut< L1<T, Ts...>, Pred, L2
                        , bool(pred<Pred,T>::value)
                        >
    {};
  }

    template<typename L, typename Pred>
    using remove = typename detail::remove_if_impl<L, Pred>::type;


namespace detail
{
    template< typename L1, typename T, typename L2 = clear<L1>>
    struct remove_element_impl
    {
      using type = L2;
    };

    template< template<class...> class L1, typename T, typename... Ts,
              typename U, template<class...> class L2, typename... Us >
    struct remove_element_impl<L1<T, Ts...>, U, L2<Us...>>
    : remove_element_impl<L1<Ts...>, U, L2<Us..., T>>
    {};

    template< template<class...> class L1, typename T, typename... Ts,
              template<class...> class L2, typename... Us >
    struct remove_element_impl<L1<T, Ts...>, T, L2<Us...>>
    : remove_element_impl<L1<Ts...>, T, L2<Us...>>
    {};
}

    template<typename L, typename T>
    using remove_element = typename detail::remove_element_impl<L, T>::type;
}

#include <type_traits>
#include <utility>

namespace brigand
{
  template<typename C, typename T, typename F>
  inline typename std::enable_if<C::value,T&&>::type select(T&& t, F&&)
  {
    return std::forward<T>(t);
  }

  template<typename C, typename T, typename F>
  inline typename std::enable_if<!C::value,F&&>::type select(T&&, F&& f)
  {
    return std::forward<F>(f);
  }
}


#include <type_traits>


namespace brigand
{
  template <typename A>
  struct complement : std::integral_constant < typename A::value_type
    , typename A::value_type(~A::value)
  > {};

  template <std::size_t Index>
  struct complement<placeholders<Index>> : detail::unary_placeholder_adaptor<brigand::complement> {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct divides : std::integral_constant < typename A::value_type, A::value / B::value > {};
}

namespace brigand
{
  template<class T>
  struct identity
  {
    using type = T;
  };
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct max : std::integral_constant < typename A::value_type
                                      , (A::value < B::value) ? B::value : A::value
                                      >
  {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct min : std::integral_constant < typename A::value_type
                                      , (A::value < B::value) ? A::value : B::value
                                      >
  {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct minus : std::integral_constant < typename A::value_type, A::value - B::value > {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct modulo : std::integral_constant < typename A::value_type, A::value % B::value > {};
}
#include <type_traits>

namespace brigand
{
  template <typename A>
  struct negate : std::integral_constant < typename A::value_type, -A::value > {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct plus : std::integral_constant < typename A::value_type, A::value + B::value > {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct times : std::integral_constant < typename A::value_type, A::value * B::value > {};
}


namespace brigand
{
  template <typename A, typename B>
  struct equal_to : bool_ < (A::value == B::value) > {};
}

namespace brigand
{
  template <typename A, typename B>
  struct greater : bool_<(A::value > B::value) > {};
}

namespace brigand
{
  template <typename A, typename B>
  struct greater_equal : bool_ < (A::value >= B::value) > {};
}

namespace brigand
{
  template <typename A, typename B>
  struct less : bool_ < (A::value < B::value) > {};
}

namespace brigand
{
  template <typename A, typename B>
  struct less_equal : bool_ < (A::value <= B::value) > {};
}

namespace brigand
{
  template <typename A, typename B>
  struct not_equal_to : bool_ < (A::value != B::value) > {};
}

#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct and_ : std::integral_constant <typename A::value_type, A::value && B::value > {};
}
#include <type_traits>

namespace brigand
{
  template <typename T>
  struct not_ : std::integral_constant<typename T::value_type, !T::value> {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct or_ : std::integral_constant < typename A::value_type, A::value || B::value > {};
}
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  struct xor_ : std::integral_constant<typename A::value_type, A::value != B::value> {};
}


namespace brigand
{
namespace detail
{
    template<template<class> class F, unsigned N, class T>
    struct repeat_impl
    : repeat_impl<F, N-7, F<F<F<F<F<F<F<T>>>>>>>>
    {};

    template<template<class> class F, class T>
    struct repeat_impl<F, 7, T>
    {
        using type = F<F<F<F<F<F<F<T>>>>>>>;
    };

    template<template<class> class F, class T>
    struct repeat_impl<F, 6, T>
    {
        using type = F<F<F<F<F<F<T>>>>>>;
    };

    template<template<class> class F, class T>
    struct repeat_impl<F, 5, T>
    {
        using type = F<F<F<F<F<T>>>>>;
    };

    template<template<class> class F, class T>
    struct repeat_impl<F, 4, T>
    {
        using type = F<F<F<F<T>>>>;
    };

    template<template<class> class F, class T>
    struct repeat_impl<F, 3, T>
    {
        using type = F<F<F<T>>>;
    };

    template<template<class> class F, class T>
    struct repeat_impl<F, 2, T>
    {
        using type = F<F<T>>;
    };

    template<template<class> class F, class T>
    struct repeat_impl<F, 1, T>
    {
        using type = F<T>;
    };

    template<template<class> class F, class T>
    struct repeat_impl<F, 0, T>
    {
        using type = T;
    };
}

    template<template<class> class F, class N, class T>
    using repeat = typename detail::repeat_impl<F, N::value, T>::type;
}




namespace brigand { namespace detail
{
  template <template <class...> class L, class First, class... R>
  struct without_last_element
  {
    using type = append<L<First>, typename without_last_element<L, R...>::type>;
  };

  template <template <class...> class L, class Last>
  struct without_last_element<L, Last>
  {
    using type = empty_list;
  };

    template <class... R> struct last_element;

  template <class T0>
  struct last_element<T0>
  {
    using type = T0;
  };

  template <class T0,class T1>
  struct last_element<T0,T1>
  {
    using type = T1;
  };

  template <class T0,class T1,class T2>
  struct last_element<T0,T1,T2>
  {
    using type = T2;
  };

  template <class T0,class T1,class T2,class T3>
  struct last_element<T0,T1,T2,T3>
  {
    using type = T3;
  };

  template <class T0,class T1,class T2,class T3,class T4>
  struct last_element<T0,T1,T2,T3,T4>
  {
    using type = T4;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5>
  struct last_element<T0,T1,T2,T3,T4,T5>
  {
    using type = T5;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6>
  struct last_element<T0,T1,T2,T3,T4,T5,T6>
  {
    using type = T6;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7>
  struct last_element<T0,T1,T2,T3,T4,T5,T6,T7>
  {
    using type = T7;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7,class... R>
  struct last_element<T0,T1,T2,T3,T4,T5,T6,T7,R...>
  {
    using type = typename last_element<R...>::type;
  };
} }

namespace brigand
{
    namespace detail
  {
    template<class L, class... T> struct push_back_impl;

    template<template<class...> class L, class... U, class... T>
    struct push_back_impl<L<U...>, T...>
    {
        using type = L<U..., T...>;
    };
  }

  template<class L, class... T>
  using push_back = typename detail::push_back_impl<L, T...>::type;

    namespace detail
  {
    template<class L> struct back_impl;

    template<template<class...> class L, class... U>
    struct back_impl<L<U...>>
    {
      using type = typename last_element<U...>::type;
    };

  }

  template <class L>
  using back = typename detail::back_impl<L>::type;

    namespace detail
  {
    template <class L> struct pop_back_impl;

    template<template<class...> class L, class... U>
    struct pop_back_impl<L<U...>>
    {
        using type = typename without_last_element<L, U...>::type;
    };
  }

  template <class L>
  using pop_back = typename detail::pop_back_impl<L>::type;
}

namespace brigand
{
    template<class L, class... T> struct push_front_impl;

  template<template<class...> class L, class... U, class... T>
  struct push_front_impl<L<U...>, T...>
  {
      using type = L<T..., U...>;
  };

  template<class L, class... T>
  using push_front = typename push_front_impl<L, T...>::type;

    template <class First, class...>
  struct first_element
  {
      using type = First;
  };

  template<class L> struct front_impl;

  template<template<class...> class L, class... U>
  struct front_impl<L<U...>>
  {
      using type = typename first_element<U...>::type;
  };

  template <class L>
  using front = typename front_impl<L>::type;

    template <template <class...> class L, class First, class... R>
  struct without_first_element
  {
      using type = L<R...>;
  };

  template <class L> struct pop_front_impl;

  template<template<class...> class L, class... U>
  struct pop_front_impl<L<U...>>
  {
      using type = typename without_first_element<L, U...>::type;
  };

  template <class L>
  using pop_front = typename pop_front_impl<L>::type;
}

#include <type_traits>





namespace brigand
{
namespace detail
{
    template<int Index, class L1, class L2>
    struct erase_c_impl;

    template< int Index,
            template<class...> class L1, class First, class... T,
      template<class...> class L2, class... U >
    struct erase_c_impl<Index, L1<First, T...>, L2<U...>>
    {
        using type = typename erase_c_impl<Index-1, L1<T...>, L2<U..., First>>::type;
    };

    template< template<class...> class L1, class First, class... T,
            template<class...> class L2, class... U >
    struct erase_c_impl<0, L1<First, T...>, L2<U...>>
    {
        using type = L2<U..., T...>;
    };
}

namespace detail
{

    template <class... U>
    struct exact_eraser;

    template <>
    struct exact_eraser<>
    {
        template <typename K>
        static exact_eraser<> erase(type_<K>);
    };

    template <class U0>
    struct exact_eraser<U0>
    {
        static exact_eraser<> erase(type_<U0>);

        template <typename K>
        static exact_eraser<U0> erase(type_<K>);
    };

    template <class U0, class... U>
    struct exact_eraser<U0, U...>
    {
        static exact_eraser<U...> erase(type_<U0>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0>, recursive_exact_erase<K>> erase(type_<K>);
    };

        template <class U0, class U1, class... U>
    struct exact_eraser<U0, U1, U...>
    {
        static exact_eraser<U1, U...> erase(type_<U0>);
        static exact_eraser<U0, U...> erase(type_<U1>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1>, recursive_exact_erase<K>> erase(type_<K>);
    };

    template <class U0, class U1, class U2, class... U>
    struct exact_eraser<U0, U1, U2, U...>
    {
        static exact_eraser<U1, U2, U...> erase(type_<U0>);
        static exact_eraser<U0, U2, U...> erase(type_<U1>);
        static exact_eraser<U0, U1, U...> erase(type_<U2>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1, U2>, recursive_exact_erase<K>> erase(type_<K>);
    };

    template <class U0, class U1, class U2, class U3, class... U>
    struct exact_eraser<U0, U1, U2, U3, U...>
    {
        static exact_eraser<U1, U2, U3, U...> erase(type_<U0>);
        static exact_eraser<U0, U2, U3, U...> erase(type_<U1>);
        static exact_eraser<U0, U1, U3, U...> erase(type_<U2>);
        static exact_eraser<U0, U1, U2, U...> erase(type_<U3>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1, U2, U3>, recursive_exact_erase<K>> erase(type_<K>);
    };

    template <class U0, class U1, class U2, class U3, class U4, class... U>
    struct exact_eraser<U0, U1, U2, U3, U4, U...>
    {
        static exact_eraser<U1, U2, U3, U4, U...> erase(type_<U0>);
        static exact_eraser<U0, U2, U3, U4, U...> erase(type_<U1>);
        static exact_eraser<U0, U1, U3, U4, U...> erase(type_<U2>);
        static exact_eraser<U0, U1, U2, U4, U...> erase(type_<U3>);
        static exact_eraser<U0, U1, U2, U3, U...> erase(type_<U4>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1, U2, U3, U4>, recursive_exact_erase<K>> erase(type_<K>);
    };

}

 template< class L, int Index >
  using erase_c = typename detail::erase_c_impl<Index, L, clear<L>>::type;

namespace detail
{
    template< class L, class Index >
    struct erase_impl
    {
        using type = erase_c<L, Index::value>;
    };

    template< class L1, template<class> class Pred, class L2 >
    struct erase_if_impl;

    template< class L1, template<class> class Pred, class L2, bool >
    struct erase_if_shortcut;

    template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
    struct erase_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, true>
    {
        using type = L2<Us..., Ts...>;
    };

    template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
    struct erase_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, false>
    : erase_if_impl<L1<Ts...>, Pred, L2<Us..., T>>
    {};

    template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred, class L2 >
    struct erase_if_impl<L1<T, Ts...>, Pred, L2>
    : erase_if_shortcut<L1<T, Ts...>, Pred, L2, bool(Pred<T>::value)>
    {};

    template< template<class...> class L1,
            template<class> class Pred,
            class L2 >
    struct erase_if_impl<L1<>, Pred, L2>
    {
        using type = L2;
    };

    template <typename T>
    struct has_erase_method
    {
        struct dummy {};

        template <typename C, typename P>
        static auto test(P * p) -> decltype(C::erase(type_<P>{}), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };


    template<class L, class I, bool>
    struct erase_dispatch
    {
        using type = typename erase_impl<L, I>::type;
    };

    template<class C, class K>
    struct erase_dispatch<C, K, true>
    {
        using type = decltype(C::erase(type_<K>{}));
    };
}

    template<class L, class K>
    using erase = typename detail::erase_dispatch<L, K, detail::has_erase_method<L>::value>::type;
}


namespace brigand
{
namespace detail
{
    template <class C, class T>
    struct insert_impl
    {
        using type = decltype(C::insert(type_<T>{}));
    };
}

    template<class L, class T>
    using insert = typename detail::insert_impl<L, T>::type;
}


namespace brigand
{
namespace detail
{
    template <class L, class K>
    struct contains_impl
    {
        using type = decltype(L::contains(type_<K>{}));
    };
}
    template <class L, class K>
    using contains = typename detail::contains_impl<L, K>::type;
}

namespace brigand
{
namespace detail
{

    template<class... Ts>
    struct make_set;

    template <class... T>
    struct set_impl
    {
        template <typename U, typename = decltype(static_cast<type_<U>>(make_set<T...>()))>
        static true_ contains(type_<U>);

        template <typename U>
        static false_ contains(U);

    private:
                template <class K>
        struct contains_predicate_impl
        {
            using type = decltype(set_impl<T...>::contains(K{}));
        };

        template <typename K>
        using contains_predicate = typename contains_predicate_impl<K>::type;

    public:
        template <typename U>
        static contains_predicate<type_<U>> has_key(type_<U>);

    public:
        template <class K>
        static wrap<decltype(exact_eraser<T...>::erase(type_<K>{})), detail::set_impl> erase(type_<K>);

    private:
        template<class K>
        static set_impl<T..., K> insert_impl(false_);

        template<class K>
        static set_impl insert_impl(true_);

    public:
        template<class K>
        static decltype(set_impl<T...>::insert_impl<K>(contains_predicate<type_<K>>())) insert(type_<K>);

    };

            template<class... Ts>
    struct make_set : type_<Ts>...
    {
      using type = set_impl<Ts...>;
    };

}

    template<class... Ts>
    using set = typename detail::make_set<Ts...>::type;

}


#endif
