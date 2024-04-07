#include "../List.cpp"
#include <catch2/catch_all.hpp>
//#include <catch2/catch_test_macros.hpp>
//#include <catch2/catch_session.hpp>

TEST_CASE("Task #2:", "[List]") {
	List list;

	// Push & Pop Front
	for (int i = 1; i <= 10; i++) {
		list.PushFront(i);
		INFO("WRONG SIZE");
		REQUIRE(list.Size() == i);
	}
	for (int i = 10; i >= 1; i--) {
		INFO("INCORRECT CONTENT");
		CHECK(list.PopFront() == i);
		INFO("WRONG SIZE");
		REQUIRE(list.Size() == i - 1);
	}

	// Check for empty list
	//REQUIRE_THROWS(list.PopFront());
	REQUIRE_THROWS_WITH(list.PopFront(), "list is empty");

	// Push & Pop Back
	for (int i = 1; i <= 10; i++) {
		list.PushBack(i);
		INFO("WRONG SIZE");
		REQUIRE(list.Size() == i);
	}
	for (int i = 10; i >= 1; i--) {
		INFO("INCORRECT CONTENT");
		CHECK(list.PopBack() == i);
		INFO("WRONG SIZE");
		REQUIRE(list.Size() == i - 1);
	}

	// Check for empty list
	//REQUIRE_THROWS(list.PopBack());
	REQUIRE_THROWS_WITH(list.PopBack(), "list is empty");

	list.Clear();
}

int main() {
	return Catch::Session().run();
}