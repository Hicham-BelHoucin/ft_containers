const array = [15, 20, 2, 10, 25, 5, 8];

array.map((item, i) => {
  setTimeout(() => {
    document.getElementsByTagName("input")[0].value = item;
    document.getElementsByTagName("input")[1].click();
  }, i * 1000);
});

/*
 // if (!rbt.IsBlanced())
        // {
        //     std::cout << 19 << BOLDRED << "\n\n shit i'm not happy now " << std::endl;
        //     // break;
        // }
            // rbt.Inorder();
    // for (std::vector<int>::iterator i = numbers.begin(); i  != numbers.end(); i++)
    srand(time(NULL));
    // std::vector<int> numbers;
    // std::random_device rd;
    // std::mt19937 g(rd());
    // for (int i = 0; i < 50; i++)
    //     numbers.push_back(i);
    // std::shuffle(numbers.begin(), numbers.end(), g);
    for (int i = 0; i < 1000000; i++)
    {
        int num = std::rand() % INT_MAX + 1;
        // int num = numbers[i];
        rbt.set(num);
        if (!rbt.IsBlanced())
        {
            std::cout << num << BOLDRED << "\n\n shit i'm not happy now " << std::endl;
            // rbt.Inorder();
            break;
        }
        std::cout << "\033[1;32m INSETRTED              " << num << "           SUCCESSFULY" << std::endl;
        usleep(2500);
        // std::system("clear");
        
    }


 */
