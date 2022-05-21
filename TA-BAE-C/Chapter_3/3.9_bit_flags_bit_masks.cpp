#include <iostream>
#include <bitset>

int _3_9()
{
	using namespace std;

	{
		bool item1_flag = false;
		bool item2_flag = false;
		bool item3_flag = false;
		bool item4_flag = false;

		// event!
		item1_flag = true;

		// die! item2 lost
		item2_flag = false;

		if (item3_flag == true)
		{
			// some events
		}

		if (item3_flag == true && item4_flag == false)
		{
			item3_flag = false;
			item4_flag = true;
		}

		// ...
	}
	
	// Especially in game, bit flags and bit masks are useful.
	{
		const unsigned char opt0 = 1 << 0;
		const unsigned char opt1 = 1 << 1;
		const unsigned char opt2 = 1 << 2;
		const unsigned char opt3 = 1 << 3;

		cout << bitset<8>(opt0) << endl;
		cout << bitset<8>(opt1) << endl;
		cout << bitset<8>(opt2) << endl;
		cout << bitset<8>(opt3) << endl;

		unsigned char items_flag = 0;
		cout << "No item: " << bitset<8>(items_flag) << endl;

		// item0 on
		items_flag |= opt0;
		cout << "Item0 obtained: " << bitset<8>(items_flag) << endl;

		// item3 on
		items_flag |= opt3;
		cout << "Item3 obtained: " << bitset<8>(items_flag) << endl;

		// item3 lost
		items_flag &= ~opt3;
		cout << "Item3 lost: " << bitset<8>(items_flag) << endl;

		// has item1 ?
		if (items_flag & opt1)
			cout << "Has item1" << endl;

		// has item0 ?
		if (items_flag & opt0)
			cout << "Has item0" << endl;

		// obtain item 2, 3
		items_flag |= (opt2 | opt3);
		cout << "opt2 | opt3: " << bitset<8>(opt2 | opt3) << endl;
		cout << "Item2, 3 obtained: " << bitset<8>(items_flag) << endl;

		// if has item2 and doesn't have item1,
		// lose item2 and get item1
		if ((items_flag & opt2) && !(items_flag & opt1))
		{
			items_flag ^= opt2; // conversion
			items_flag ^= opt1;
		}
		cout << "items_flag: " << bitset<8>(items_flag) << endl;
	}

	// In graphics, bit flags is useful.
	{
		// gl_clear(XXX_XXXXX_XXX | XXX_XXXX_XX)
 	}

	// RGB Color, bit masks are useful.
	{
		unsigned int pixel_color = 0xDAA520;
		cout << "pixel_color:\t" << bitset<32>(pixel_color) << endl;

		const unsigned int red_mask = 0xFF0000;
		const unsigned int green_mask = 0x00FF00;
		const unsigned int blue_mask = 0x0000FF;

		cout << "red_mask:\t" << bitset<32>(red_mask) << endl;
		cout << "green_mask:\t" << bitset<32>(green_mask) << endl;
		cout << "blue_mask:\t" << bitset<32>(blue_mask) << endl;
		
		unsigned char red = (pixel_color & red_mask) >> 16;
		unsigned char green = (pixel_color & green_mask) >> 8;
		unsigned char blue = (pixel_color & blue_mask);
		
		cout << "red:\t" << bitset<8>(red) << " " << int(red) << endl;
		cout << "green:\t" << bitset<8>(green) << " " << int(green) << endl;
		cout << "blue:\t" << bitset<8 >(blue) << " " << int(blue) << endl;
	}

	return 0;
}