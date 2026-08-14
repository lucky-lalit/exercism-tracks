"""Functions to keep track and alter inventory."""


def create_inventory(items):
    """Create a dict that tracks the amount (count) of each element on the `items` list.

    Parameters:
        items (list): Items to create an inventory from.

    Returns:
        dict: The inventory dictionary.
    """
    result = {}
    unique_list = []
    for i in items:
        if i not in unique_list:
            unique_list.append(i)
            result[i] = items.count(i)
    return result

def add_items(inventory, items):
    """Add or increment items in inventory using elements from the items `list`.

    Parameters:
        inventory (dict): Dictionary of existing inventory.
        items (list): List of items to update the inventory with.

    Returns:
        dict: The inventory updated with the new items.
    """

    for key,value in inventory.items():
        for i in range(value):
            items.append(key)
    return create_inventory(items)


def decrement_items(inventory, items):
    """Decrement items in inventory using elements from the `items` list.

    Parameters:
        inventory (dict): Inventory dictionary.
        items (list): List of items to decrement from the inventory.

    Returns:
        dict: Updated inventory with items decremented.
    """
    for i in items:
        if (inventory.get(i,'not found') == 'not found'):
            continue
        else:
            value = inventory[i]
            value = value - 1
            if (value < 0):
                inventory[i] = 0
            else:
                inventory[i] = value
    return inventory


def remove_item(inventory, item):
    """Remove item from inventory if it matches `item` string.

    Parameters:
        inventory (dict): Inventory dictionary.
        item (str): Item to remove from the inventory.

    Returns:
        dict: Updated inventory with item removed. Current inventory if item does not match.
    """
    if (inventory.get(item,'not found') == 'not found'):
        return inventory
    temp = inventory.pop(item)
    return inventory


def list_inventory(inventory):
    """Create a list containing only available (item_name, item_count > 0) pairs in inventory.

    Parameters:
        inventory (dict): An inventory dictionary.

    Returns:
        list[tuple]: List of key, value tuples from the inventory dictionary.
    """
    # tup = ()
    lis = []
    for key,value in inventory.items():
        tup = ()
        if value == 0:
            continue
        else:
            tup = tup + (key,)
            tup = tup + (value,)
            lis.append(tup)
    return lis
