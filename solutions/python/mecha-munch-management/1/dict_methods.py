"""Functions to manage a users shopping cart items."""


def add_item(current_cart, items_to_add):
    """Add items to shopping cart.

    :param current_cart: dict - the current shopping cart.
    :param items_to_add: iterable - items to add to the cart.
    :return: dict - the updated user cart dictionary.
    """

    for i in items_to_add:
        value = current_cart.setdefault(i,0)
        current_cart[i] = value + 1
    return current_cart


def read_notes(notes):
    """Create user cart from an iterable notes entry.

    :param notes: iterable of items to add to cart.
    :return: dict - a user shopping cart dictionary.
    """

    result = {}
    unique_list = []
    for i in notes:
        if i not in unique_list:
            unique_list.append(i)
            result[i] = notes.count(i)
    return result


def update_recipes(ideas, recipe_updates):
    """Update the recipe ideas dictionary.

    :param ideas: dict - The "recipe ideas" dict.
    :param recipe_updates: iterable -  with updates for the ideas section.
    :return: dict - updated "recipe ideas" dict.
    """
    ideas |= recipe_updates
    return ideas

def sort_entries(cart):
    """Sort a users shopping cart in alphabetically order.

    :param cart: dict - a users shopping cart dictionary.
    :return: dict - users shopping cart sorted in alphabetical order.
    """
    sorted_dict = dict(sorted(cart.items()))
    return sorted_dict

def send_to_store(cart, aisle_mapping):
    """Combine users order to aisle and refrigeration information.

    :param cart: dict - users shopping cart dictionary.
    :param aisle_mapping: dict - aisle and refrigeration information dictionary.
    :return: dict - fulfillment dictionary ready to send to store.
    """

    for keys,values in aisle_mapping.items():
        for fruit in cart.keys():
            if (fruit == keys):
                count = cart[fruit]
                values.insert(0,count)
                break
                
    new = {}
    # for outer_key,outer_value in aisle_mapping.items():
    #     for inner_key,inner_value in cart.items():
    #         if (outer_key == inner_key):
    #             new.setdefault(inner_key,outer_value)

    for inner_key,inner_value in cart.items():
        outer_value = aisle_mapping.get(inner_key,None)
        if outer_value != None:
            new[inner_key] = outer_value
            
    sorted_dict = dict(sorted(new.items()))
    
    temp = {}
    for item in reversed(sorted_dict.items()):
        temp.setdefault(item[0],item[1])
    return temp

def update_store_inventory(fulfillment_cart, store_inventory):
    """Update store inventory levels with user order.

    :param fulfillment cart: dict - fulfillment cart to send to store.
    :param store_inventory: dict - store available inventory
    :return: dict - store_inventory updated.
    """
    for outer_key,outer_value in fulfillment_cart.items():
        for inner_key,inner_value in store_inventory.items():
            if outer_key == inner_key:
                old_count = inner_value[0]
                new_count = outer_value[0]
                inner_value[0] = old_count - new_count
                if inner_value[0] <= 0:
                    inner_value[0] = 'Out of Stock'
                break
    return store_inventory