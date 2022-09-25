
#pragma once
#include <type_traits>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <execution>

namespace
{
	template<typename T>
	using arithmetic = std::enable_if_t<std::is_arithmetic_v<T>, T>;

	template<typename Iterator>
	using iter_value_t = typename std::iterator_traits<Iterator>::value_type;

	template<typename Iter, typename T = arithmetic<iter_value_t<Iter> > >
	auto add(Iter beg, Iter end)->T
	{
		return std::reduce(std::execution::seq,
			beg,
			end,
			T{ 0 },
			std::plus<T>());
	}

	template<typename Iter, typename T = arithmetic<iter_value_t<Iter> >, typename Pred>
	decltype(auto) add_if(Iter beg, Iter end, Pred&& pred)
	{		
		if constexpr (std::is_invocable_r_v<bool, Pred, const T&>)
		{
			auto retval{ T{0} };
			std::for_each(std::execution::seq,
				beg,
				end,
				[&](const T & val)
				{
					if (std::forward<Pred>(pred)(val))
						retval += val;
				});
			return retval;
		}		
	}
}
