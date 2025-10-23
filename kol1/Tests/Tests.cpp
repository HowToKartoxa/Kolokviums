#include <catch2/catch_test_macros.hpp>
#include <utils/funcs.h>
#include <utils/single_linked_list.h>


TEST_CASE("n_factorial computes factorial sequence correctly", "[n_factorial]") 
{
    SECTION("Valid input") 
    {
        auto result = n_factorial(5);
        std::vector<size_t> expected = { 1, 2, 6, 24, 120 };
        REQUIRE(result == expected);
    }

    SECTION("Edge case n = 1") 
    {
        auto result = n_factorial(1);
        std::vector<size_t> expected = { 1 };
        REQUIRE(result == expected);
    }

    SECTION("Throws exception for n = 0") 
    {
        REQUIRE_THROWS_AS(n_factorial(0), std::invalid_argument);
    }
}


TEST_CASE("n_factorial with modulo computes under modulo", "[n_factorial_modulo]") 
{
    SECTION("Modulo operation applied correctly") 
    {
        auto result = n_factorial(5, 10);
        std::vector<size_t> expected = { 1, 2, 6, 4, 0 };
        REQUIRE(result == expected);
    }
}


TEST_CASE("remove_duplicates removes duplicates and preserves order", "[remove_duplicates]") 
{
    SECTION("No duplicates") 
    {
        std::vector<double> input = { 1.0, 2.0, 3.0 };
        auto result = remove_duplicates(input);
        REQUIRE(result == input);
    }

    SECTION("With duplicates") 
    {
        std::vector<double> input = { 1.0, 2.0, 1.0, 3.0, 2.0 };
        auto result = remove_duplicates(input);
        std::vector<double> expected = { 1.0, 2.0, 3.0 };
        REQUIRE(result == expected);
    }

    SECTION("Empty vector") 
    {
        std::vector<double> input;
        auto result = remove_duplicates(input);
        REQUIRE(result.empty());
    }
}

TEST_CASE("SingleLinkedList Reverse reverses the list", "[Reverse]") 
{
    SECTION("Empty list") 
    {
        SingleLinkedList<int> list;
        list.Reverse();
        REQUIRE(list.head == nullptr);
    }

    SECTION("Single element") 
    {
        SingleLinkedList<int> list;
        list.head = new Node<int>(5);
        list.Reverse();
        REQUIRE(list.head->data == 5);
        REQUIRE(list.head->next == nullptr);
    }

    SECTION("Multiple elements") 
    {
        SingleLinkedList<int> list;
        list.head = new Node<int>(1);
        list.head->next = new Node<int>(2);
        list.head->next->next = new Node<int>(3);
        list.head->next->next->next = nullptr;

        list.Reverse();

        REQUIRE(list.head->data == 3);
        REQUIRE(list.head->next->data == 2);
        REQUIRE(list.head->next->next->data == 1);
        REQUIRE(list.head->next->next->next == nullptr);
    }
}