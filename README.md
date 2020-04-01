Known bug:

As we submitted the project, we noticed that we had a bug in the remove item function. We were using Inventory[slot] to remove an item at Slot 'slot'.
However this was not the correct way to go about this since when we sort the inventory, slots will be in a different order.
A possible solution would be to receive the slot itself as a parameter or create an auxiliary function that returned the slot based on the slot number.

Possible solution:

auto* slot = Inventory.FindByPredicate([](const InventorySlot& Slot) {
	return Slot.slot == slotnumber;
});

Due to lack of time, we were unable to properly do this change and fully test it in time for the submission.
