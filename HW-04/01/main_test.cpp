#include "List.cpp"
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
		CHECK(list.Empty() == false);
		INFO("WRONG SIZE");
		CHECK(list.Size() == num);

		for (int i = -1; i >= (-10); i--) {
			list.PushBack(i);
		}
		CHECK(list.Empty() == false);
		INFO("WRONG SIZE");
		CHECK(list.Size() == 2 * num);

		list.Clear();
		INFO("NOT CLEARED");
		REQUIRE(list.Size() == 0);
}

TEST_CASE("Task #2:", "[List]") {
	List list;
	REQUIRE(list.Empty() == true);
	REQUIRE(list.Size() == 0);

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

	list.Clear();
	INFO("NOT CLEARED");
	REQUIRE(list.Size() == 0);
}

int main() {
	return Catch::Session().run();
}