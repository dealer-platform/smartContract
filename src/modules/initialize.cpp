ACTION reporting::init() {
  	int usercount = 0;
	for(auto& row : _users) { 
		usercount++;
	}

	if(usercount == 0){
	reguser("peter"_n, "",true);
    reguser("emma"_n, "",true);
    reguser("isabelle"_n, "",true);
    reguser("bob"_n, "",true);
    reguser("mallory"_n, "",true);
		reguser("carl"_n, "",true);
	reguser("simon"_n, "",true);
	}


}

void reporting::insertitem(name reporter, string hash, int price, string description, string title, bool sale, bool report){
	require_auth( _self );

		int pk =  _items.available_primary_key();

		_items.emplace(_self, [&]( auto& row ) { 
			row.key = pk;
			row.reporter = reporter;
			row.hash = hash;
			row.price = price;
			row.description = description;
			row.title = title;
			row.sale = sale;
			row.report = report;
		});

	int reward = price * rewardpercent / 100;

	assignverifier(pk, reward);
}


