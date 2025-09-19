#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include "AVL.h"

using namespace std;
//UF ID: 23793962
//Name: Angela Acquista

TEST_CASE("Test 1: Incorrect Commands", "[incorrect]"){

	MyAVLTree tree;
	REQUIRE(tree.insert("Poo Pee", "A11y") == false); 
	REQUIRE(tree.insert("Doo Dee", "45679999") == false);
	REQUIRE(tree.insert("Ooga Booga", "-123456") == false);
	REQUIRE(tree.insert("", "87654321") == false);
	REQUIRE(tree.insert("Wack Back", "1234A567") == false);
}

TEST_CASE("Test 2: Insert and Rotate", "[rotations]"){
	
	MyAVLTree tree;

	SECTION("Left-Left Rotation Case") {

		tree.insert("third", "3");
		tree.insert("second", "2"); 
		tree.insert("first", "1");  
		REQUIRE((tree.inorder()).size() == 3);
		REQUIRE(tree.search("3") == true);
		REQUIRE(tree.search("2") == true);
		REQUIRE(tree.search("1") == true);
	}
	SECTION("Right-Right Rotation Case") {

		tree.insert("fourth", "4");
		tree.insert("fifth", "5");
		tree.insert("sixth", "6"); 
		REQUIRE((tree.inorder()).size() == 3);
		REQUIRE(tree.search("4") == true);
		REQUIRE(tree.search("5") == true);
		REQUIRE(tree.search("6") == true);
	}
	SECTION("Left-Right Rotation Case") {

		tree.insert("ninth", "9");
		tree.insert("seventh", "7");
		tree.insert("eighth", "8");
		REQUIRE((tree.inorder()).size() == 3);
		REQUIRE(tree.search("9") == true);
		REQUIRE(tree.search("8") == true);
		REQUIRE(tree.search("7") == true);
	}
	SECTION("Right-Left Rotation Case") {

		tree.insert("tenth", "10");
		tree.insert("twelfth", "12");
		tree.insert("eleventh", "11"); 
		REQUIRE((tree.inorder()).size() == 3);
		REQUIRE(tree.search("10") == true);
		REQUIRE(tree.search("12") == true);
		REQUIRE(tree.search("11") == true);
	}
}

TEST_CASE("Test 3: Insert and Delete", "[deletions]"){
	
	MyAVLTree tree;
	random_device rd;
	mt19937 gen(rd());
	vector<string> ids, removing;

	for(int i = 1; i <= 100; i++){
		
		string id = to_string(10000000 + i); 
		string name = "Student" + to_string(i);
		REQUIRE(tree.insert(name, id) == true);
		ids.push_back(id);
	}
	REQUIRE(ids.size() == 100);
	vector<string> ordered = tree.inorder();
	REQUIRE(ordered.size() == 100);

	for(size_t i = 1; i < ordered.size(); i++){
		
		REQUIRE(stoll(ordered.at(i)) > stoll(ordered.at(i - 1)));
	}
	vector<string> remaining = ids;
	
	for(int i = 0; i < 10; i++){
		
		uniform_int_distribution<> dis(0, remaining.size() - 1);
		int rand = dis(gen);
		removing.push_back(remaining.at(rand));
		remaining.erase(remaining.begin() + rand);
	}
	for(const auto& id : removing){
		
		REQUIRE(tree.remove(id) == true);
	}
	vector<string> final = tree.inorder();
	REQUIRE(final.size() == 90);
	
	for(size_t i = 1; i < final.size(); i++){
		
		REQUIRE(stoll(final.at(i)) > stoll(final.at(i - 1)));
	}
	for(const auto& removed : removing){
		
		REQUIRE(tree.search(removed) == false);
	}
	for(const auto& remains : remaining){
		
		REQUIRE(tree.search(remains) == true);
	}
}
// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

TEST_CASE("Example BST Insert", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/
}
