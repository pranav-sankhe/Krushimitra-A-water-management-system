from kivy.app import App 
from kivy.uix.button import Button 
from kivy.uix.floatlayout import FloatLayout 
from kivy.uix.boxlayout import BoxLayout 
from kivy.uix.dropdown import DropDown
from kivy.uix.button import Button
from kivy.core.window import Window
from kivy.uix.behaviors import CompoundSelectionBehavior
from kivy.uix.behaviors import FocusBehavior
from kivy.uix.gridlayout import GridLayout
from kivy.core.window import Window

class SelectableGrid(FocusBehavior, CompoundSelectionBehavior, GridLayout):

    def __init__(self, **kwargs):
        super(SelectableGrid, self).__init__(**kwargs)

        def print_selection(*l):
            print('selected: ', [x.text for x in self.selected_nodes])
        self.bind(selected_nodes=print_selection)

    def keyboard_on_key_down(self, window, keycode, text, modifiers):
        if super(SelectableGrid, self).keyboard_on_key_down(
            window, keycode, text, modifiers):
            return True
        if self.select_with_key_down(window, keycode, text, modifiers):
            return True
        return False

    def keyboard_on_key_up(self, window, keycode):
        if super(SelectableGrid, self).keyboard_on_key_up(window, keycode):
            return True
        if self.select_with_key_up(window, keycode):
            return True
        return False

    def goto_node(self, key, last_node, last_node_idx):
        ''' This function is used to go to the node by typing the number
        of the text of the button.
        '''
        node, idx = super(SelectableGrid, self).goto_node(key, last_node,
                                                          last_node_idx)
        if node != last_node:
            return node, idx

        items = list(enumerate(self.get_selectable_nodes()))
        '''If self.nodes_order_reversed (the default due to using
        self.children which is reversed), the index is counted from the
        starts of the selectable nodes, like normal but the nodes are traversed
        in the reverse order.
        '''
        # start searching after the last selected node
        if not self.nodes_order_reversed:
            items = items[last_node_idx + 1:] + items[:last_node_idx + 1]
        else:
            items = items[:last_node_idx][::-1] + items[last_node_idx:][::-1]

        for i, child in items:
            if child.text.startswith(key):
                return child, i
        return node, idx


    def select_node(self, node):
        node.background_color = (1, 0, 0, 1)
        krishi_object = node.parent.parent.parent.parent.children[1]
        if self.id == 'crop':
        	krishi_object.crop_type_show.text += node.text
        elif self.id == 'soil':
        	krishi_object.soil_type_show.text += node.text
        return super(SelectableGrid, self).select_node(node)

    def deselect_node(self, node):
        node.background_color = (1, 1, 1, 1)
        krishi_object = node.parent.parent.parent.parent.children[1]
        if self.id == 'crop':
        	krishi_object.crop_type_show.text = 'crop_type'
        elif self.id == 'soil':
        	krishi_object.soil_type_show.text = 'soil_type'
        super(SelectableGrid, self).deselect_node(node)

    def do_touch(self, instance, touch):
        if ('button' in touch.profile and touch.button in
            ('scrollup', 'scrolldown', 'scrollleft', 'scrollright')) or\
            instance.collide_point(*touch.pos):
            self.select_with_touch(instance, touch)
        else:
            return False
        return True

class CustomDropDown(DropDown):
    pass


class Krishi(BoxLayout):
	def __init__(self, **kwargs):
		#print Window._is_desktop
		super(Krishi, self).__init__(**kwargs)
		root = self
		self.orientation = 'vertical'
		self.inner_level_box = GridLayout(cols=2)
		self.release_btn = Button(text='Release Water', size_hint=(1,0.1))

		self.dropdown1 = CustomDropDown(size_hint_y=1)
		self.dropdown2 = CustomDropDown(size_hint_y=1)

		text=['crop_type','soil_type']
		crop_type_options=['a','b','c','d','e']
		soil_type_options=['1','2','3','4','5']

		self.crop_type_show=Button(text='crop_type',size_hint_y=None, height=50)
		self.crop_type_show.bind(on_release=self.dropdown1.open)
		self.soil_type_show=Button(text='soil_type', size_hint_y=None,height=50)
		self.soil_type_show.bind(on_release=self.dropdown2.open)

		grid1 =SelectableGrid(cols=1, multiselect=True,size_hint=(None,None),height=300,width=400,id='crop',
							touch_multiselect=True)
		for index in range(len(crop_type_options)):
			btn = Button(text=crop_type_options[index], size_hint_y=None, height=44)
			btn.bind(on_touch_down=grid1.do_touch)
			grid1.add_widget(btn)
		self.dropdown1.add_widget(grid1)

		grid2 =SelectableGrid(cols=1,multiselect=True,size_hint=(None,None),height=300,width=400,id='soil',
							touch_multiselect=True)
		for index in range(len(soil_type_options)):
			btn = Button(text=soil_type_options[index], size_hint_y=None, height=44)
			btn.bind(on_touch_down=grid2.do_touch)
			grid2.add_widget(btn)
		self.dropdown2.add_widget(grid2)
		
		self.inner_level_box.add_widget(self.crop_type_show)
		self.inner_level_box.add_widget(self.soil_type_show)
		self.add_widget(self.inner_level_box)
		self.add_widget(self.release_btn)

	def show_crop_type(self):
		crop_type=SelectableGrid(cols=1, up_count=5, multiselect=True,
								scroll_count=1,touch_multiselect=True)
		crop_type_options=['a','b','c','d','e']
		for index in range(len(self.crop_type_options)):
			btn = Button(text=crop_type_options[index], size_hint_y=None, height=44)
			btn.bind(on_touch_down=crop_type.do_touch)
			crop_type.add_widget(btn)
		self.dropdown1.add_widget(crop_type)

	def show_soil_type(self):
		soil_type=SelectableGrid(cols=1, up_count=5, multiselect=True,
								scroll_count=1,touch_multiselect=True)
		soil_type_options=['1','2','3','4','5']
		for index in range(len(self.soil_type_options)):
			btn = Button(text=soil_type_options[index], size_hint_y=None, height=44)
			btn.bind(on_touch_down=soil_type.do_touch)
			soil_type.add_widget(btn)
		self.dropdown1.add_widget(soil_type)


class KrishiApp(App):
	def build(self):
		return Krishi()
if __name__== '__main__':
	KrishiApp().run()