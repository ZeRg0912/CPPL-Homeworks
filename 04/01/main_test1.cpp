#include "../List.cpp"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("Task #1", "[List]") {
		List list;
		REQUIRE(list.Empty() == true);
		REQUIRE(list.Size() == 0);

		int num = 10;
		for (int i = 0; i < num; i++) {
			list.PushBack(i);
		}
		INFO("WRONG SIZE");
		CHECK(list.Size() == num);

		for (int i = -1; i >= (-10); i--) {
			list.PushBack(i);
		}
		INFO("WRONG SIZE");
		CHECK(list.Size() == 2 * num);

		list.Clear();
		INFO("NOT CLEARED");
		REQUIRE(list.Size() == 0);
}

int main() {
	return Catch::Session().run();
}