#ifndef CPPDNN_HEADER_NETWORK_HPP
#define CPPDNN_HEADER_NETWORK_HPP

#include <cppdnn/layer.hpp>
#include <cppdnn/object.hpp>

#include <vector>

namespace cppdnn
{
	template<typename Ty_>
	class basic_network
	{
	public:
		basic_network() = default;
		basic_network(const basic_network& network) = delete;
		basic_network(basic_network&& network) = delete;
		~basic_network() = default;

	public:
		basic_network& operator=(const basic_network& network) = delete;
		basic_network& operator=(basic_network&& network) = delete;
		bool operator==(const basic_network& network) = delete;
		bool operator!=(const basic_network& network) = delete;
		basic_network& operator<<(const basic_layer_ptr<Ty_>& layer);

	public:
		template<typename Layer_, typename... Args_>
		void add_layer(Args_&&... args);
		void add_layer(const basic_layer_ptr<Ty_>& layer);

		basic_object_ptr<Ty_> compute(const basic_object_ptr<Ty_>& input) const;

	public:
		const std::vector<basic_layer_ptr<Ty_>>& layers() const noexcept;

	private:
		std::vector<basic_layer_ptr<Ty_>> layers_;
	};

	using network = basic_network<double>;
}

#include "details/network.hpp"
#endif